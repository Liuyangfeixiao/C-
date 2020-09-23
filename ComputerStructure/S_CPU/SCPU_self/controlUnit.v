module ControlUnit(
    input clk,
    input rst,
    input[5:0] Opcode,
    input[5:0] func,
    input[4:0] Rt, //Instr[20:16]
    //input[1:0] RscmpRt,
    //input[1:0] RscmpZ,
    input Zero,
    output reg memRd,
    output reg memWt,
    output reg RegWre,
    output reg ExtSel,
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

// Control Signals
    assign RegDst = (Opcode == 6'b000000) ? 1 : 0;
    assign PCWre = (Opcode == 6'b111111) ? 0 : 1;
    assign ExtSel = (Opcode == 6'b001100 || Opcode == 6'b001101 || Opcode == 6'b001110) ? 0 : 1;
    assign DBDataSrc = (Opcode == 6'b100000 || Opcode == 6'b100001 || Opcode == 6'b100011 || Opcode == 6'b100100 || Opcode == 6'b100101) ? 1 : 0;
    assign mWR = (Opcode == 6'b101000 || Opcode == 6'b101001 || Opcode == 6'b101011) ? 1 : 0;
    assign mRD = (Opcode == 6'b100000 || Opcode == 6'b100001 || Opcode == 6'b100011 || Opcode == 6'b100100 || Opcode == 6'b100101) ? 1 : 0;

    assign ALUSrcA[0] = (Opcode == 6'b000000 && (func == 6'b000000 || func == 6'b000011 || func == 6'b000010))? 1:0;
    assign ALUSrcA[1] = (Opcode == 6'b001111)?1:0;

    assign ALUSrcB[0] = (Opcode == 6'b000000 || Opcode == 6'b000001 || Opcode == 6'b000100 || Opcode == 6'b000101 || Opcode == 6'b000110 || Opcode == 6'b000111) ? 0 : 1;
    assign ALUSrcB[1] = (Opcode == 6'h01 || Opcode == 6'h06 || Opcode == 6'h07)? 1:0;
    assign RegWre = ((Opcode == 6'b000000 && func == 6'b001000) || Opcode == 6'b101000 || Opcode == 6'b101001 || Opcode == 6'b101011 || Opcode == 6'b000100||Opcode == 6'b000101||Opcode == 6'b000110||Opcode == 6'b000111) ? 0 : 1;

    // PCSrc - choose next address
    assign PCSrc [0] = ((Opcode == 6'b000001&&zero == 0 && rt == 5'd0) || (Opcode == 6'b000001&&zero == 1 && rt == 5'd1) || (Opcode == 6'b000100&&zero == 1) || (Opcode == 6'b000101 && zero == 0) || (Opcode == 6'b000110 && zero == 1) || (Opcode == 6'b000111 && zero == 0) || (Opcode == 6'h0 && (func == 6'd8 || func == 6'd9))) ? 1 : 0;
    assign PCSrc [1] = (Opcode == 6'b000010 || (Opcode == 6'b000000 && (func == 6'b001000 || func == 6'b001001))) ? 1 : 0;

    // ALUOp - choose ALU functions
    assign ALUOp [0] = ((Opcode == 6'd0 && (func == 6'd2 || func == 6'd6 || func == 6'd8 || func == 6'd9 || func == 6'd34 || func == 6'd35 || func == 6'd37 || func == 6'd39 || func == 6'd43)) || Opcode == 6'h02 || Opcode == 6'h03 || Opcode == 6'h04 || Opcode == 6'h05 || Opcode == 6'h06 || Opcode == 6'h07 ||Opcode == 6'h0B || Opcode == 6'h0D) ? 0 : 1;
    assign ALUOp [1] = ((Opcode == 6'h0 && (func == 6'd2 || func == 6'd3 || func == 6'd6 || func == 6'd7 || func == 6'd34 || func == 6'd35 || func == 6'd36 || func == 6'd38)) || Opcode == 6'h04 || Opcode == 6'h05 || Opcode == 6'h0B || Opcode == 6'h0C || Opcode == 6'h0E) ? 1 : 0;
    assign ALUOp [2] = ((Opcode == 6'h0 && (func == 6'd38 || func == 6'd37)) || Opcode == 6'h01 || Opcode == 6'h06 || Opcode == 6'h06 || Opcode == 6'h07 || Opcode == 6'h0A || Opcode == 6'h0B || Opcode == 6'h0D || Opcode == 6'h0E) ? 1 : 0;
    assign ALUOp [3] = ((Opcode == 6'h0 && (func == 6'd0 || func == 6'd2 || func == 6'd3 || func == 6'd4 || func == 6'd6 || func == 6'd7)) || Opcode == 6'h06 || Opcode == 6'h07 || Opcode == 6'h0F) ? 1:0;

    assign Load[0] = (Opcode == 6'h24 || Opcode == 6'h25) ? 1:0;
    assign Load[1] = (Opcode == 6'h21 || Opcode == 6'h25)? 1:0;
    assign Load[2] = (Opcode == 6'h23)? 1:0;

    assign Store[0] = (Opcode == 6'h29)? 1:0;
    assign Store[1] = (Opcode == 6'h2B)? 1:0;
    assign InsMemRW = 1;

endmodule // ControlUnit