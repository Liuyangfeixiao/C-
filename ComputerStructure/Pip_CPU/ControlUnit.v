module ControlUnit(
    input clk,
    input rst,
    input[5:0] Opcode,
    input[5:0] func,
    input[4:0] Rt, //Instr[20:16]
    input[1:0] RscmpRt,
    input[1:0] RscmpZ,
    input Zero,
    output reg memRd,
    output reg memWt,
    output reg RegWre,
    output reg Extsel,
    output reg[1:0] PCSrc,
    output reg[1:0] RegDst,
    output reg[1:0] ALUSrc_A,
    output reg ALUSrc_B,
    output reg[3:0] ALUOp,
    output reg[2:0] Load,
    output reg[1:0] Store,
    output reg[1:0] MemtoReg, //choose from PC+4, MemData, ALUresult
    output reg JumpSrc
);

initial
begin
    {memRd, memWt, RegWre} <= 3'b0;
    ALUOp <= 4'b0;
    PCSrc <= 0;
    RegDst <= 0;
    Load <= 0;
    Store <= 0;
    ALUSrc_A <= 0;
    ALUSrc_B <= 0;
    MemtoReg <= 0;
end

always @(*) begin
    if(rst)
    begin
        {memRd, memWt, RegWre} <= 3'b0;
        ALUOp <= 4'b0;
        PCSrc <= 0;
        RegDst <= 0;
        Load <= 0;
        Store <= 0;
        ALUSrc_A <= 0;
        ALUSrc_B <= 0;
        MemtoReg <= 0;
    end

    else
    begin
    //ALUOp
    ALUOp [0] = ((Opcode == 6'd0 && (func == 6'd2 || func == 6'd6 || func == 6'd8 || func == 6'd9 || func == 6'd34 || func == 6'd35 || func == 6'd37 || func == 6'd39 || func == 6'd43)) || Opcode == 6'h01|| Opcode == 6'h02 || Opcode == 6'h03 || Opcode == 6'h04 || Opcode == 6'h05 || Opcode == 6'h06 || Opcode == 6'h07 ||Opcode == 6'h0B || Opcode == 6'h0D) ? 0 : 1;
    ALUOp [1] = ((Opcode == 6'h0 && (func == 6'd2 || func == 6'd3 || func == 6'd6 || func == 6'd7 || func == 6'd34 || func == 6'd35 || func == 6'd36 || func == 6'd38 || func == 6'd43)) || Opcode == 6'h0B || Opcode == 6'h0C || Opcode == 6'h0E) ? 1 : 0;
    ALUOp [2] = ((Opcode == 6'h0 && (func == 6'd38 || func == 6'd37 || func == 6'd42 || func == 6'd43)) || Opcode == 6'h0A || Opcode == 6'h0B || Opcode == 6'h0D || Opcode == 6'h0E) ? 1 : 0;
    ALUOp [3] = ((Opcode == 6'h0 && (func == 6'd0 || func == 6'd2 || func == 6'd3 || func == 6'd4 || func == 6'd6 || func == 6'd7 || func == 6'd39)) || Opcode == 6'h0F) ? 1:0;
    //PCSrc
    case (Opcode)
        6'h00:begin
            if(func == 6'd8 || func == 6'd9) //jr, jalr
                PCSrc = 2'b11;
            else
                PCSrc = 2'b00;
        end
        6'h01:begin
            if((Rt == 0 &&(RscmpZ == 2'b00)) || (Rt == 1 &&(RscmpZ == 2'b01 || RscmpZ == 2'b10))) //bltz,bgez
                PCSrc =2'b01;
            else
                PCSrc = 2'b00;
        end 
        6'h02, 6'h03:PCSrc = 2'b10; //j, jal
        6'h04: begin                //beq
            if(RscmpRt == 2'b01)
                PCSrc = 2'b01;
            else
                PCSrc = 2'b00;
        end
        6'h05:begin                 //bne
            if(RscmpRt == 2'b01)
                PCSrc = 2'b00;
            else
                PCSrc = 2'b01;
        end
        6'h06: begin                //blez
            if(RscmpZ == 2'b00 || RscmpZ == 2'b01)
                PCSrc = 2'b01;
            else
                PCSrc = 2'b00;
        end
        6'h07: begin                //bgtz
            if(RscmpZ == 2'b10)
                PCSrc = 2'b01;
            else
                PCSrc = 2'b00;
        end
        default: PCSrc = 2'b00;
    endcase

    //RegDst
    if (Opcode == 6'h03) //jal
        RegDst = 2'b00;
    else if(Opcode == 6'h00) //R-type
        RegDst = 2'b10;
    else 
        RegDst = 2'b01;   //I-type
    //RegWrite
    RegWre = ((Opcode == 6'b000000 && func == 6'b001000) || Opcode == 6'b101000 || Opcode == 6'b101001 || Opcode == 6'b101011 || Opcode == 6'b000010|| Opcode == 6'b000100||Opcode == 6'b000101||Opcode == 6'b000110||Opcode == 6'b000111) ? 0 : 1;
    //ALUSrcA
    if((Opcode == 6'h00 && (func == 6'b000000 || func == 6'b000011 || func == 6'b000010)))
        ALUSrc_A = 2'b01;
    else if(Opcode == 6'h0F)
        ALUSrc_A = 2'b10;
    else
        ALUSrc_A = 2'b00;
    //ALUSrcB
    if(Opcode == 6'h00 || Opcode == 6'h04 || Opcode == 6'h05) //R-type, beq, bne
        ALUSrc_B = 0;
    else
        ALUSrc_B = 1; //offset
    
    //Load
    case (Opcode)
        6'h20: Load = 3'b000;
        6'h24: Load = 3'b001;
        6'h21: Load = 3'b010;
        6'h25: Load = 3'b011;
        6'h23: Load = 3'b100;
        default: Load = 3'b100;
    endcase

    //Store
    case (Opcode)
        6'h28: Store = 2'b00; 
        6'h29: Store = 2'b01;
        6'h2B: Store = 2'b10;
        default: Store = 2'b10;
    endcase

    end

    //Extsel
    if(Opcode == 6'b001100 || Opcode == 6'b001101 || Opcode == 6'b001110)//ANDI, XORI, ORI
        ExtSel = 0;
    else
        ExtSel = 1;
    //MEMtoREG

    if (Opcode == 6'h03 || (Opcode == 6'h00 && func == 6'd9)) begin
        MemtoReg = 2'b00;
    end
    else if(Opcode == 6'h20 || Opcode == 6'h21 || Opcode == 6'h23 || Opcode == 6'h24 || Opcode == 6'h25)
    begin
        MemtoReg = 2'b10;
    end
    else
        MemtoReg = 2'b01;
end

endmodule // ControlUnit