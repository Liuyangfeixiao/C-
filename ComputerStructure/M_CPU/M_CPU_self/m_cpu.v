module m_cpu(
    input clk,
    input reset,
    output[3:0] state_out,
    output[5:0] Opcode,
    output[5:0] func,
    output[31:0] Data1,
    output[31:0] Data2,
    output[31:0] DataA, 
    output[31:0] DataB,
    output[31:0] tempWrite,
    output[31:0] writedata,
    output[31:0] pc,
    output[31:0] npc,
    output[31:0] result,
    output[4:0] rs,
    output[4:0] rt,
    output[31:0] DataOut
);


    wire[31:0] ADR_out, BDR_out, ALU_out, MEM_out;
    wire[3:0] ALUOp;
    wire[31:0] ExtOut;
    wire[25:0] JumpAddr;
    wire[15:0] immediate;
    wire[4:0]  rd, sa, out1;
    wire[31:0] rd_e, sa_e, out1_e, rt_e;
    wire[1:0] PCSrc;
    wire[1:0] ALUSrcA, ALUSrcB;
    wire[1:0]RegDst;
    wire zero, sign, PCWre, ExtSel, DBDataSrc, mWR, mRD, InsMemRW, RegWre, WrRegData;
    
    
    wire[2:0] Load;
    wire[1:0] Store;
    

//InsMem
InsMem insmem(pc, InsMemRw, Opcode, rs, rt, rd, sa, func, immediate, JumpAddr);

//controlUnit
controlUnit CU(Opcode, func, rt, zero, sign, clk, reset, InsMemRW, PCWre, ExtSel, DBDataSrc, mWR, mRD, WrRegData, RegDst, Load, Store, ALUSrcA, ALUSrcB, PCSrc, ALUOp, state_out, RegWre);

//Mux RegDst
assign rd_e = 27'b0 + rd;
assign rt_e = 27'b0 + rt;

mux4 mux_RDst(32'h1F, rt_e, rd_e, 0, RegDst, out1_e);
assign out1 = out1_e[4:0];

//DBDataSrc
mux2 DB_Src(result, DataOut, DBDataSrc, tempWrite);
DataLate MEMDR(clk, tempWrite, MEM_out);

//RF
RF regfile(clk, reset, RegWre, rs, rt, out1, writedata, Data1, Data2);
DataLate ADR(clk, Data1, ADR_out);
DataLate BDR(clk, Data2, BDR_out);

//ALUSrcA, ALUSrcB
assign sa_e = 27'b0 + sa;
mux4 ALU_A(ADR_out, sa_e, 16, 0, ALUSrcA, DataA);
mux4 ALU_B(BDR_out, ExtOut, 0, 0, ALUSrcB, DataB);

//ALU
alu alu_x(DataA, DataB, ALUOp, result, zero, sign, clk);

DataLate ALUDR(clk, result, ALU_out);
//DataMem
DataMem datamem(ALU_out, Data2, Load, Store, mRD, mWR, DataOut);

//WrRegData

mux2 wrRegData(pc+4, MEM_out, WrRegData, writedata);

//Extended
EXT ext(immediate, ExtSel, ExtOut);

//NPC
NPC NPC_1(pc, PCSrc, JumpAddr, npc, Data1);
//PC
PC Pc(clk, reset, PCWre, npc, pc);

endmodule
