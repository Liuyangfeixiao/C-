//`include "alu.v"
//`include "ctrl_encode_def.v"
//`include "EXT.v"
//`include "mux.v"
//`include "NPC.v"
//`include "PC.v"
//`include "RF.v"
//`include "IM.v"
//`include "DM.v"
//`include "Control.v"
//`include "ALUControl.v"

module s_cpu( input wire clk,
input wire reset,
input wire MIO_ready, // Not used
input wire [31:0] inst_in, //指令输入总线
input wire [31:0]Data_in, //数据输入总线
output wire mem_w, //存储器读写控��
output wire[31:0]PC_out, //程序空间访问指针
output wire[31:0]Addr_out, //数据空间访问地址
output wire[31:0]Data_out, //数据输出总线
output wire CPU_MIO, // Not used
input wire INT //中断
);

wire [31:0] pc;
wire [31:0] npc;
wire [2:0]  NPCOp;
wire [31:0] RD1;
wire Zero;
wire [1:0]   EXTOp;
wire [31:0]  Imm32;
wire RFWr;
wire [4:0]   A3;
wire [31:0]  RD2;
wire [31:0]  WD;
wire [3:0]   ALUOp;
wire [31:0]  A;
wire [31:0]  B;
wire [31:0]  C;
wire ALUSrc1;
wire ALUSrc2;
wire [1:0]   RegDst;
wire [1:0]   toReg;
wire [1:0]   DMWr;
wire [3:0]   DMRd;

PC Pc(clk, rst, npc, pc);
NPC Npc(.pc(pc),         .NPCOp(NPCOp),   .IMM(inst_in[25:0]), .Rt(inst_in[20:16]), 
                      .RD1(RD1),       .Zero(Zero),     .npc(npc));
assign PC_out = pc;

EXT EXT(inst_in[15:0], EXTOp, Imm32);

RF RegFile(clk, rst, RFWr, inst_in[25:21], inst_in[20:16], A3, 
WD, RD1, RD2);

assign Data_out = RD2;

assign Addr_out = C;
alu Alu(A, B, ALUOp, C, Zero);

mux2 ALUmux1    ( .d0(RD1),        .d1({27'b0,inst_in[10:6]}),  .s(ALUSrc1), .y(A) );
mux2 ALUmux2    ( .d0(RD2),        .d1(Imm32),      .s(ALUSrc2),    .y(B) );
mux4 RegDstmux  ( .d0(inst_in[20:16]), .d1(inst_in[15:11]), .d2(31),        .d3(0), .s(RegDst), .y(A3) );   
mux4 toRegmux   ( .d0(C),          .d1(Data_in),    .d2(pc+4),      .d3(0), .s(toReg),  .y(WD) );

ctrl_unit CU(inst_in[31:26], inst_in[5:0], RegDst, NPCOp, DMRd, toReg,
ALUOp, DMWr, ALUSrc1, ALUSrc2, RFWr, EXTOp);

assign mem_w = DMWr[0];

endmodule

    