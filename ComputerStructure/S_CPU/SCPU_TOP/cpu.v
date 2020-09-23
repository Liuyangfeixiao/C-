`include "alu.v"
`include "ctrl_unit.v"
`include "EXT.v"
`include "mux.v"
`include "NPC.v"
`include "PC.v"
`include "RF.v"
`include "ctrl_encode_def.v"

module cpu( clk, rst, Data_in, inst_in, Pc, Data_out, Addr_out, mem_w );
    input           clk;
    input           rst;
    input   [31:0]  Data_in;
    input   [31:0]  inst_in;

    output          mem_w;
    output  [31:0]  Addr_out;
    output  [31:0]  Pc;
    output  [31:0]  Data_out;

    //PC & NPC
    wire    [31:0]  pc;
    wire    [31:0]  npc;
    wire    [2:0]   NPCOp;
    wire    [31:0]  RD1;
    wire            Zero;
    PC      PC      ( .clk(clk),       .rst(rst),       .npc(npc),   .pc(pc) );
    NPC     NPC     ( .pc(pc),         .NPCOp(NPCOp),   .IMM(inst_in[25:0]), .Rt(inst_in[20:16]), 
                      .RD1(RD1),       .Zero(Zero),     .npc(npc) );
	assign  Pc = pc;


    //EXT
    wire    [1:0]   EXTOp;
    wire    [31:0]  Imm32;
    EXT     EXT     ( .Imm16(inst_in[15:0]), .EXTOp(EXTOp), .Imm32(Imm32) );


    //RF
    wire            RFWr;
    wire    [4:0]   A3;   
    //wire  [31:0]  RD1;
    wire    [31:0]  RD2;
    wire    [31:0]  WD;
    RF      RF      ( .clk(clk), .rst(rst), .RFWr(RFWr), .A1(inst_in[25:21]), .A2(inst_in[20:16]), .A3(A3),
                      .WD(WD),   .RD1(RD1), .RD2(RD2) );
    assign Data_out = RD2;

    //ALU
    //wire          Zero;
    wire    [3:0]   ALUOp;
    wire    [31:0]  A;
    wire    [31:0]  B;
    wire    [31:0]  C;
    assign Addr_out = C;
    alu      alu    ( .A(A), .B(B), .ALUOp(ALUOp), .C(C), .Zero(Zero) );


    //MUX
    wire            ALUSrc1;
    wire            ALUSrc2;
    wire    [1:0]   RegDst;
    wire    [1:0]   toReg;
    mux2 ALUmux1    ( .d0(RD1),        .d1({27'b0,inst_in[10:6]}),  .s(ALUSrc1), .y(A) );
    mux2 ALUmux2    ( .d0(RD2),        .d1(Imm32),      .s(ALUSrc2),    .y(B) );
    mux4 RegDstmux  ( .d0(inst_in[20:16]), .d1(inst_in[15:11]), .d2(31),        .d3(0), .s(RegDst), .y(A3) );   
    mux4 toRegmux   ( .d0(C),          .d1(Data_in),    .d2(pc+4),      .d3(0), .s(toReg),  .y(WD) );

    //control unit
	wire    [1:0]   DMWr;
    wire    [3:0]   DMRd;
    ctrl_unit ctrl_unit( .opcode(inst_in[31:26]), .func(inst_in[5:0]), 
                         .RegDst(RegDst),     .NPCOp(NPCOp),    .DMRd(DMRd), .toReg(toReg), 
                         .ALUOp(ALUOp),       .DMWr(DMWr),      .ALUSrc1(ALUSrc1), 
                         .ALUSrc2(ALUSrc2),   .RFWr(RFWr),      .EXTOp(EXTOp) );

    assign mem_w = DMWr[0];

endmodule