`include "MUX.v"
module pipeline_CPU(clk, rst);
input clk;
input rst;

//---------------IF Stage----------------------------
wire [31:0] PCPlus_IF;
wire [31:0] PCBranch_ID;
wire [31:0] PCJump_ID;
wire [31:0] PCJR_ID;
wire [1:0] PCSrc_ID;
wire [31:0] nextPC;
wire [31:0] pc;
wire PCWre;
wire [31:0] IMem_out;

mux4 MUXPC(.d0(PCPlus_IF), .d1(PCBranch_ID), .d2(PCJump_ID), 
.d3(PCJR_ID), .s(PCSrc_ID), .y(nextPC));

PC Pc(.clk(clk), .rst(rst), .NPC(nextPC), .PC(pc), .PCWre(PCWre));

PCAdd4 pcadd4(.PC_o(pc), .PCPlus4(PCPlus_IF));

InsMem IMem(.PC(pc), .instruction(IMem_out));
//----------------------IFID----------------------------
wire [31:0] Ins_IFID;
wire [31:0] PCPlus_IFID;
IFIDREG IFID(.clk(clk), .rst(rst), .IF_Stall(IF_Stall), .IF_Flush(IF_Flush), 
            .Instruction_in(IMem_out), .PCPlus4_in(PCPlus_IF), .Instruction_out(Ins_IFID), .PCPlus4_out(PCPlus_IFID));

//----------------------ID---------------------------------
wire [25:0] JumpImm;
wire [5:0] Func;
wire [5:0] Shamt;
wire [15:0] Imm16;
wire [4:0] Rd;
wire [4:0] Rt;
wire [4:0] Rs;
wire [5:0] Op;

assign JumpImm = Ins_IFID[25:0];
assign Func = Ins_IFID[5:0];
assign Shamt = Ins_IFID[10:6];
assign Imm16 = Ins_IFID[15:0];
assign Rd = Ins_IFID[15:11];
assign Rt = Ins_IFID[20:16];
assign Rs = Ins_IFID[25:21];
assign Op = Ins_IFID[31:26];

wire [31:0] ImmExtened;
wire [1:0] RscmpRt;
wire [1:0] RscmpZ;
wire memRd, memWt, RegWre, Exsel, ALUSrc_B, JumpSrc;
//wire [1:0] PCSrc_ID;
wire [1:0] RegDst, ALUSrc_A, Store, MemtoReg;
wire [3:0] ALUOp;
wire [2:0] Load;
wire [31:0] ShamtExtended;
wire [31:0] RsData,RtData;
assign ShamtExtended = {27'b0, {Shamt}};


ControlUnit control(.clk(clk), .rst(rst), .Opcode(Op), .func(Func), .Rt(Rt), .RscmpRt(RscmpRt), .RscmpZ(RscmpZ), 
.memRd(memRd), .memWt(memWt), .RegWre(RegWre), .Exsel(Exsel), .PCSrc(PCSrc_ID), .RegDst(RegDst), .ALUSrc_A(ALUSrc_A), 
.ALUSrc_B(ALUSrc_B), .ALUOp(ALUOp), .Load(Load), .Store(Store), .MemtoReg(MemtoReg), .JumpSrc(JumpSrc));

EXT16 EXT(Imm16, Exsel, ImmExtened);

RF regfile(clk, rst, RegWre_MEMWB, Rs, Rt, RegWriteAddr_WB, RegWriteData_WB, RsData, RtData);

assign PCBranch_ID = PCPlus_IFID + {{14{Imm16[15]}}, Imm16[15:0], 2'b00};
assign PCJump_ID = {PCPlus_IFID[31:28], JumpImm[25:0], 2'b00};
assign PCJR_ID = RsData;
assign IF_Flush = (PCSrc_ID != 2'b00); //???????????

wire [31:0] RsData_final1, RsData_final2, RtData_final;

mux2 Forward_C(RsData, ALUResult_EXMEM, ForwardC, RsData_final1);
mux2 Forward_D(RtData, ALUResult_EXMEM, ForwardD, RtData_final);
mux2 Forward_E(RsData, ALUResult_EXMEM, ForwardE, RsData_final2);


Compare cmp1(RsData_final1, RtData_final, RscmpRt);
Compare cmp2(RsData_final2, 0, RscmpZ);
//--------------------------------------IDEX------------------------------------------------
wire ID_Flush;
wire [31:0] PCPlus_IDEX;
wire [31:0] RsData_IDEX;
wire [31:0] RtData_IDEX;
wire [31:0] ImmExtened_IDEX;
wire [31:0] ShamtExtended_IDEX;
wire [4:0] RsAddr_IDEX;
wire [4:0] RtAddr_IDEX;
wire [4:0] RdAddr_IDEX;
wire [1:0] RegDst_IDEX;
wire [1:0] ALUSrcA_IDEX;
wire ALUSrcB_IDEX;
wire [3:0] ALUOp_IDEX;
wire MemRd_IDEX;
wire MemWt_IDEX;
wire [2:0] Load_IDEX;
wire [1:0] Store_IDEX;
wire [1:0] MemtoReg_IDEX;
wire RegWre_IDEX;
HazardUnit Hazard(Op, Rs, Rt, .RtAddr_IDEX(RtAddr_IDEX), .RtAddr_EXMEM(RtAddr_EXMEM), .MemRd_EXMEM(MemRd_EXMEM), .MemRd_IDEX(MemRd_IDEX), .IFID_Stall(IF_Stall), .PCWre(PCWre), .IDEX_Flush(ID_Flush));
wire ID_Stall;
assign ID_Stall = 0;
IDEXREG IDEX(clk, rst, ID_Stall, ID_Flush, PCPlus_IFID, RsData, RtData, ImmExtened, ShamtExtended, Rs, Rt, Rd, PCPlus_IDEX, RsData_IDEX, RtData_IDEX, 
ImmExtened_IDEX, ShamtExtended_IDEX, RsAddr_IDEX, RtAddr_IDEX, RdAddr_IDEX, RegDst, ALUSrc_A, ALUSrc_B, ALUOp, memRd, memWt, Load, Store, MemtoReg, RegWre,
RegDst_IDEX, ALUSrcA_IDEX, ALUSrcB_IDEX, ALUOp_IDEX, MemRd_IDEX, MemWt_IDEX, Load_IDEX, Store_IDEX, RegWre_IDEX);

//------------------------------------------EX-----------------------------------------------
wire [1:0] ForwardA, ForwardB;
wire ForwardC, ForwardD, ForwardE;
wire [4:0] RegWriteAddr;
wire [31:0] tmp_ForwardA, tmp_ForwardB;
wire [31:0] tmp_ALUSrcA, tmp_ALUSrcB;
wire [31:0] ALUResult;
wire Zero;

mux4 RegWriteSel(0x1F, RtAddr_IDEX, RdAddr_IDEX, 0, RegDst_IDEX, RegWriteAddr);
mux4 Forward_A(.d0(RsData_IDEX), .d1(ALUResult_EXMEM), .d2(RegWriteData_WB), .s(ForwardA), .y(tmp_ForwardA));
mux4 Forward_B(.d0(RtData_IDEX), .d1(ALUResult_EXMEM), .d2(RegWriteData_WB), .s(ForwardB), .y(tmp_ForwardB));

mux4 aLUSrc_A(tmp_ForwardA, ShamtExtended_IDEX, 32'd16, 0, ALUSrcA_IDEX, tmp_ALUSrcA);
mux2 aLUSrc_B(tmp_ForwardB, ImmExtened_IDEX, ALUSrcB_IDEX, tmp_ALUSrcB);

ALU alu(tmp_ALUSrcA, tmp_ALUSrcB, ALUOp_IDEX, ALUResult, Zero);

ForwardUnit Forward(Op, Rs, Rt, RsAddr_IDEX, RtAddr_IDEX, RegWriteAddr_EXMEM, RegWriteAddr_WB, RegWre_EXMEM, RegWre_MEMWB, 
ForwardA, ForwardB, ForwardC, ForwardD, ForwardE);

//------------------------------------EXMEM----------------------------------------------------
wire [31:0] ALUResult_EXMEM, MemWriteData, PCPlus_EXMEM;
wire [4:0] RegWriteAddr_EXMEM;
wire MemRd_EXMEM, MemWt_EXMEM;
wire [2:0] Load_EXMEM;
wire [1:0] Store_EXMEM;
wire [1:0] MemtoReg_EXMEM;
wire RegWre_EXMEM;
wire EX_Stall;
wire EX_lush;
assign EX_Stall = 1'b0;
assign EX_Flush = 1'b0;
EXMEMREG EXMEM(clk, rst, EX_Stall, EX_Flush, PCPlus_IDEX, ALUResult, tmp_ForwardB, RegWriteAddr, PCPlus_EXMEM, ALUResult_EXMEM, MemWriteData, RegWriteAddr_EXMEM,
MemRd_IDEX, MemWt_IDEX, Load_IDEX, Store_IDEX, MemtoReg_IDEX, RegWre_IDEX, MemRd_EXMEM, MemWt_EXMEM, Load_EXMEM, Store_EXMEM, MemtoReg_EXMEM, RegWre_EXMEM);

//-----------------------------------MEM-----------------------------------------------------
wire [31:0] MemData;
DataMem datamem(clk, ALUResult_EXMEM, MemWriteData, Load_EXMEM, Store_EXMEM, MemRd_EXMEM, MemWt_EXMEM, MemData);

//-----------------------------------MEMWB---------------------------------------------------

wire [31:0] ALUResult_MEMWB, MemData_out, PCPlus_MEMWB;
wire [31:0] RegWriteAddr_WB;
wire [1:0] MemtoReg_MEMWB;
wire RegWre_MEMWB;
wire MEM_Stall, MEM_Flush;
assign MEM_Stall = 0;
assign MEM_Flush = 0;
//wire [4:0] RegWriteAddr_WB;
MEMWBREG MEMWB(clk, rst, MEM_Stall, MEM_Flush, PCPlus_EXMEM, ALUResult_EXMEM, MemData, RegWriteAddr_EXMEM, PCPlus_MEMWB, ALUResult_MEMWB, MemData_out, RegWriteAddr_WB, 
MemtoReg_EXMEM, RegWre_EXMEM, MemtoReg_MEMWB, RegWre_MEMWB);

//-----------------------------------WB----------------------------------------
wire [31:0] RegWriteData_WB;
mux4 WriteDataSel(PCPlus_MEMWB, ALUResult_MEMWB, MemData_out, 0, MemtoReg_MEMWB, RegWriteData_WB);

endmodule // pipeline_CPU