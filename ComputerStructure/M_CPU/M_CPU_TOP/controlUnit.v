module controlUnit(
input[5:0] Opcode,
input[5:0] func,
input[4:0] rt,
input zero,
input sign,
input clk,
input rst,
output reg InsMemRW,
output reg PCWre,
output reg ExtSel,
output reg DBDataSrc,
output reg mWR,
output reg mRD,
output reg WrRegData,
output reg [1:0]RegDst,
output reg[2:0] Load,
output reg[1:0] Store,
output reg[1:0] ALUSrcA,
output reg[1:0] ALUSrcB,
output reg[1:0] PCSrc,
output reg[3:0] ALUOp,
output reg[4:0] state_out,      // MCPU 修改 state_out 位宽
output reg RegWre,
output reg IRWrite,             // MCPU 新增信号，控制指令寄存器
output reg AddrSrc            // MCPU 新增信号，控�Data_out 的输�
);

reg [4:0] presentState;
reg [4:0] nextState;

parameter [4:0] sIF = 5'b00000,
                sID = 5'b00001,
                sEXE1 = 5'b00010,
                sEXE2 = 5'b00011, //lw, sw
                sEXE3 = 5'b00100, //beq
                sEXE4 = 5'b00101,
                sMEM1 = 5'b00110, //lw
                sMEM2 = 5'b00111, //sw
                sWB1 = 5'b01000,  //R-type
                sWB2 = 5'b01001;  // lw
                //sMEM = 3'b100;
initial 
    begin
        presentState <= sIF;
        nextState <= sID;
        RegDst <= 0;
        InsMemRW <= 0;
        PCWre <= 0;
        ExtSel <= 0;
        DBDataSrc <= 0;
        mWR <= 0;
        mRD <= 0;
        Load <= 0;
        Store <= 0;
        ALUSrcA <= 0;
        ALUSrcB <= 0;
        RegWre <= 0;
        //test <= 2'b000000;
        ALUOp <= 4'b0000;
        IRWrite <= 0;
        AddrSrc <= 0;
    end

//switch state
always @(posedge clk) begin
    if (rst)
        presentState <= sIF;
    else begin
        presentState <= nextState;
    end
    state_out <= presentState;
end

//select state

always @(presentState or Opcode) //or Opcode
begin
    case (presentState)
        sIF: nextState <= sID;
        sID: 
        begin
            case (Opcode)
                6'h00: begin
                    case(func)
                    6'd9: nextState <= sEXE4; //jalr
		    6'd8: nextState <= sIF;    //jr
                    default: nextState <= sEXE1; //R-type
                    endcase
                end
                6'h03: nextState <= sEXE4; //jal
                6'h02: nextState <= sIF; //j
                6'h20,6'h21,6'h23,6'h23,6'h24,6'h28,6'h29,6'h2B: nextState <= sEXE2; //lw,sw
                6'h01,6'h04,6'h05,6'h06,6'h07: nextState <= sEXE3; //beq
                default: nextState <= sEXE1; //I-type
            endcase
        end
        sEXE1: nextState <= sWB1; //R-type, I-type
        sEXE2: 
        begin
            case(Opcode)
            6'h20,6'h21,6'h23,6'h24,6'h25: nextState <= sMEM1; //lw
            6'h28,6'h29,6'h2B: nextState <= sMEM2; //sw
            endcase
        end
        sEXE3: nextState <= sIF; //beq
        sEXE4: nextState <= sIF; //jr,jalr ,jal
        
        sMEM1: nextState <= sWB2; //lw
        sMEM2: nextState <= sIF; //sw
        sWB1: nextState <= sIF; //R-type, I-type
        sWB2: nextState <= sIF;   //lw
        default: nextState <= sIF; 
    endcase

end

//set control signals

always @ (presentState) // MCPU 删除 or Opcode
begin
    //PCWre
    if (presentState == sIF && (ALUOp != 0 || (Opcode == 6'h00 && (func == 6'd9 || func == 6'd8)) || Opcode == 6'h02 || Opcode == 6'h03)) //j, jal, jalr, jr
        PCWre = 1;
    else
        PCWre = 0;
    //InsMemRw
    InsMemRW = 1;

    //RegWre
    if(presentState == sWB1 || presentState == sWB2 || (presentState == sEXE4 && (Opcode == 6'h03 || (Opcode == 6'h0 && func == 6'd9)))) //lw, R,I,jal,jalr
        RegWre = 1;
    else
        RegWre = 0;
    //RegDst
    if (Opcode == 6'h03) //jal
        RegDst = 2'b00;
    else if(Opcode == 6'h00) //R-type
        RegDst = 2'b10;
    else 
        RegDst = 2'b01;   //I-type
    
    //ExtSel
    if(Opcode == 6'b001100 || Opcode == 6'b001101 || Opcode == 6'b001110)
        ExtSel = 0;
    else
        ExtSel = 1;
    

    //DBDataSrc
    if(presentState == sWB2)
        DBDataSrc = 1;
    else
        DBDataSrc = 0;
    
    //mWR
    if(presentState == sMEM2)
        mWR = 1;
    else
        mWR = 0;
    
    //mRD
    if(presentState == sMEM1)
        mRD = 1;
    else
        mRD = 0;

    //WrRegData
    if(presentState == sWB1 || presentState == sWB2)
	WrRegData = 1;
    else
	WrRegData = 0;
    
    //PCSrc
    if( //presentState == sIF && 
	(Opcode == 6'h02 || Opcode == 6'h03)) // j, jal
        PCSrc = 2'b10;
    else if(((Opcode == 6'b000001&&zero == 0 && rt == 5'd0) || (Opcode == 6'b000001&&zero == 1 && rt == 5'd1) || (Opcode == 6'b000100&&zero == 1) || (Opcode == 6'b000101 && zero == 0) || (Opcode == 6'b000110 && zero == 1) || (Opcode == 6'b000111 && zero == 0)))
        PCSrc = 2'b01;
    else if((Opcode == 6'h00 && (func == 6'd8 || func == 6'd9))) // jr, jalr
        PCSrc = 2'b11;
    else
        PCSrc = 2'b00;
    

    //ALUSrcA
    if((Opcode == 6'h00 && (func == 6'b000000 || func == 6'b000011 || func == 6'b000010)))
        ALUSrcA = 2'b01;
    else if(Opcode == 6'b001111)
        ALUSrcA = 2'b10;
    else
        ALUSrcA = 2'b00;
    
    //ALUSrcB
    if(Opcode == 6'h00 || Opcode == 6'h04 || Opcode == 6'h05 )
        ALUSrcB = 2'b00;
    else if(Opcode == 6'h01 || Opcode == 6'h06 || Opcode == 6'h07)
        ALUSrcB = 2'b10;
    else
        ALUSrcB = 2'b01;
    
    //ALUOp
    ALUOp [0] = ((Opcode == 6'd0 && (func == 6'd2 || func == 6'd6 || func == 6'd8 || func == 6'd9 || func == 6'd34 || func == 6'd35 || func == 6'd37 || func == 6'd39 || func == 6'd43)) || Opcode == 6'h02 || Opcode == 6'h03 || Opcode == 6'h04 || Opcode == 6'h05 || Opcode == 6'h06 || Opcode == 6'h07 ||Opcode == 6'h0B || Opcode == 6'h0D) ? 0 : 1;
    ALUOp [1] = ((Opcode == 6'h0 && (func == 6'd2 || func == 6'd3 || func == 6'd6 || func == 6'd7 || func == 6'd34 || func == 6'd35 || func == 6'd36 || func == 6'd38 || func == 6'd43)) || Opcode == 6'h04 || Opcode == 6'h05 || Opcode == 6'h0B || Opcode == 6'h0C || Opcode == 6'h0E) ? 1 : 0;
    ALUOp [2] = ((Opcode == 6'h0 && (func == 6'd38 || func == 6'd37 || func == 6'd42 || func == 6'd43)) || Opcode == 6'h01 || Opcode == 6'h06 || Opcode == 6'h06 || Opcode == 6'h07 || Opcode == 6'h0A || Opcode == 6'h0B || Opcode == 6'h0D || Opcode == 6'h0E) ? 1 : 0;
    ALUOp [3] = ((Opcode == 6'h0 && (func == 6'd0 || func == 6'd2 || func == 6'd3 || func == 6'd4 || func == 6'd6 || func == 6'd7 || func == 6'd39)) || Opcode == 6'h06 || Opcode == 6'h07 || Opcode == 6'h0F) ? 1:0;

    //Load
    if(presentState == sMEM1)
        case (Opcode)
            6'h20: Load = 3'b000;
            6'h24: Load = 3'b001;
            6'h21: Load = 3'b010;
            6'h25: Load = 3'b011;
            6'h23: Load = 3'b100;
            default: Load = 3'b100;
        endcase
    
    //Store
    if(presentState == sMEM2)
        case (Opcode)
            6'h28: Store = 2'b00; 
            6'h29: Store = 2'b01;
            6'h2B: Store = 2'b10;
            default: Store = 2'b10;
        endcase
    
    //IRWrite
    if (presentState == sIF)
        IRWrite = 1;
    else
        IRWrite = 0;

    
    //AddrSrc
    if (presentState == sMEM1 || presentState == sMEM2)
        AddrSrc = 1;
    else
        AddrSrc = 0;



    //Avoid write data in sIF
    if (presentState == sIF) begin
            RegWre = 0;
            mRD = 0;
	        mWR = 0;
        end

end


// Control Signals
    // assign RegDst = (Opcode == 6'b000000) ? 1 : 0;
    // assign PCWre = (Opcode == 6'b111111) ? 0 : 1;
    // assign ExtSel = (Opcode == 6'b001100 || Opcode == 6'b001101 || Opcode == 6'b001110) ? 0 : 1;
    // assign DBDataSrc = (Opcode == 6'b100000 || Opcode == 6'b100001 || Opcode == 6'b100011 || Opcode == 6'b100100 || Opcode == 6'b100101) ? 1 : 0;
    // assign mWR = (Opcode == 6'b101000 || Opcode == 6'b101001 || Opcode == 6'b101011) ? 1 : 0;
    // assign mRD = (Opcode == 6'b100000 || Opcode == 6'b100001 || Opcode == 6'b100011 || Opcode == 6'b100100 || Opcode == 6'b100101) ? 1 : 0;

    // assign ALUSrcA[0] = (Opcode == 6'b000000 && (func == 6'b000000 || func == 6'b000011 || func == 6'b000010))? 1:0;
    // assign ALUSrcA[1] = (Opcode == 6'b001111)?1:0;

    // assign ALUSrcB[0] = (Opcode == 6'b000000 || Opcode == 6'b000001 || Opcode == 6'b000100 || Opcode == 6'b000101 || Opcode == 6'b000110 || Opcode == 6'b000111) ? 0 : 1;
    // assign ALUSrcB[1] = (Opcode == 6'h01 || Opcode == 6'h06 || Opcode == 6'h07)? 1:0;
    // assign RegWre = ((Opcode == 6'b000000 && func == 6'b001000) || Opcode == 6'b101000 || Opcode == 6'b101001 || Opcode == 6'b101011 || Opcode == 6'b000100||Opcode == 6'b000101||Opcode == 6'b000110||Opcode == 6'b000111) ? 0 : 1;

    // // PCSrc - choose next address
    // assign PCSrc [0] = ((Opcode == 6'b000001&&zero == 0 && rt == 5'd0) || (Opcode == 6'b000001&&zero == 1 && rt == 5'd1) || (Opcode == 6'b000100&&zero == 1) || (Opcode == 6'b000101 && zero == 0) || (Opcode == 6'b000110 && zero == 1) || (Opcode == 6'b000111 && zero == 0) || (Opcode == 6'h0 && (func == 6'd8 || func == 6'd9))) ? 1 : 0;
    // assign PCSrc [1] = (Opcode == 6'b000010 || (Opcode == 6'b000000 && (func == 6'b001000 || func == 6'b001001))) ? 1 : 0;

    // // ALUOp - choose ALU functions
    // assign ALUOp [0] = ((Opcode == 6'd0 && (func == 6'd2 || func == 6'd6 || func == 6'd8 || func == 6'd9 || func == 6'd34 || func == 6'd35 || func == 6'd37 || func == 6'd39 || func == 6'd43)) || Opcode == 6'h02 || Opcode == 6'h03 || Opcode == 6'h04 || Opcode == 6'h05 || Opcode == 6'h06 || Opcode == 6'h07 ||Opcode == 6'h0B || Opcode == 6'h0D) ? 0 : 1;
    // assign ALUOp [1] = ((Opcode == 6'h0 && (func == 6'd2 || func == 6'd3 || func == 6'd6 || func == 6'd7 || func == 6'd34 || func == 6'd35 || func == 6'd36 || func == 6'd38)) || Opcode == 6'h04 || Opcode == 6'h05 || Opcode == 6'h0B || Opcode == 6'h0C || Opcode == 6'h0E) ? 1 : 0;
    // assign ALUOp [2] = ((Opcode == 6'h0 && (func == 6'd38 || func == 6'd37)) || Opcode == 6'h01 || Opcode == 6'h06 || Opcode == 6'h06 || Opcode == 6'h07 || Opcode == 6'h0A || Opcode == 6'h0B || Opcode == 6'h0D || Opcode == 6'h0E) ? 1 : 0;
    // assign ALUOp [3] = ((Opcode == 6'h0 && (func == 6'd0 || func == 6'd2 || func == 6'd3 || func == 6'd4 || func == 6'd6 || func == 6'd7)) || Opcode == 6'h06 || Opcode == 6'h07 || Opcode == 6'h0F) ? 1:0;

    // assign Load[0] = (Opcode == 6'h24 || Opcode == 6'h25) ? 1:0;
    // assign Load[1] = (Opcode == 6'h21 || Opcode == 6'h25)? 1:0;
    // assign Load[2] = (Opcode == 6'h23)? 1:0;

    // assign Store[0] = (Opcode == 6'h29)? 1:0;
    // assign Store[1] = (Opcode == 6'h2B)? 1:0;
    //assign InsMemRW = 1;
endmodule
