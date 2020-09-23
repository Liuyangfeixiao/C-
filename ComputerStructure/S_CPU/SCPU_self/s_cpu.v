module s_cpu(
    input clk,
    input reset,
    output[5:0] Opcode,
    output[5:0] func,
    output[31:0] Data1,
    output[31:0] Data2,
    output[31:0] DataA, 
    output[31:0] DataB,
    output[31:0] writedata,
    output[31:0] pc,
    output[31:0] npc,
    output[31:0] result,
    output[4:0] rs,
    output[4:0] rt,
    output[31:0] DataOut
);

    wire[3:0] ALUOp;
    wire[31:0] ExtOut;
    wire[25:0] JumpAddr;
    wire[15:0] immediate;
    wire[4:0]  rd, sa, out1;
    wire[31:0] rd_e, sa_e, out1_e, rt_e;
    wire[1:0] PCSrc;
    wire[1:0] ALUSrcA, ALUSrcB;
    wire RegDst, zero, sign, PCWre, ExtSel, DBDataSrc, mWR, mRD, InsMemRW, RegWre;
    
    
    wire[2:0] Load;
    wire[1:0] Store;
    

//InsMem
InsMem insmem(pc, InsMemRw, Opcode, rs, rt, rd, sa, func, immediate, JumpAddr);

//controlUnit
controlUnit CU(Opcode, func, rt, zero, sign, RegDst, InsMemRW, PCWre, ExtSel, DBDataSrc, mWR, mRD, Load, Store, ALUSrcA, ALUSrcB, PCSrc, ALUOp, RegWre);
//Mux RegDst
assign rd_e = 27'b0 + rd;
assign rt_e = 27'b0 + rt;

mux2 mux_RDst(rt_e, rd_e, RegDst, out1_e);
assign out1 = out1_e[4:0];

//DBDataSrc
mux2 DB_Src(result, DataOut, DBDataSrc, writedata);

//RF
RF regfile(clk, reset, RegWre, rs, rt, out1, writedata, Data1, Data2);
//ALUSrcA, ALUSrcB
assign sa_e = 27'b0 + sa;
mux4 ALU_A(Data1, sa_e, 16, 0, ALUSrcA, DataA);
mux4 ALU_B(Data2, ExtOut, 0, 0, ALUSrcB, DataB);

//ALU
alu alu_x(DataA, DataB, ALUOp, result, zero, sign, clk);
//DataMem
DataMem datamem(result, Data2, Load, Store, mRD, mWR, clk, DataOut);


//Extended
EXT ext(immediate, ExtSel, ExtOut);

//NPC
NPC NPC_1(pc, PCSrc, JumpAddr, npc, Data1, clk);
//PC
PC Pc(clk, reset, npc, pc);

endmodule
