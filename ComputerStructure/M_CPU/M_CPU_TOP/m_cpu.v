module m_cpu(
    input  clk,
    input  reset,
    input  MIO_ready,       // Not used
    input  INT,              //中断
    input  [31:0] Data_in,   //数据输入总线

    output        mem_w,          //存储器读写控�
    output [31:0] inst_out,  //指令输出总线
    output [31:0] PC_out,    //程序空间访问指针
    output [31:0] Addr_out,  //数据空间访问地址
    output [31:0] Data_out,  //数据输出总线
    output        CPU_MIO,        // Not used
    output [4:0]  state          //状态输�

);


    wire [3:0] state_out;
    wire [5:0] Opcode;
    wire [5:0] func;
    wire [31:0] Data1;
    wire [31:0] Data2;
    wire [31:0] DataA; 
    wire [31:0] DataB;
    wire [31:0] tempWrite;
    wire [31:0] writedata;
    wire [31:0] pc;
    wire [31:0] npc;
    wire [31:0] result;
    wire [4:0] rs;
    wire [4:0] rt;
    wire [31:0] MemDataOut;


    wire[31:0] ADR_out, BDR_out, ALU_out, MEM_out;
    wire[3:0] ALUOp;
    wire[31:0] ExtOut;
    wire[25:0] JumpAddr;
    wire[15:0] immediate;
    wire[4:0]  rd, sa;
    wire[31:0] out1_e;
    wire[1:0] PCSrc;
    wire[1:0] ALUSrcA, ALUSrcB;
    wire[1:0]RegDst;
    wire zero, sign, PCWre, ExtSel, DBDataSrc, mWR, mRD, InsMemRW, RegWre, WrRegData;
    
    
    wire[2:0] Load;
    wire[1:0] Store;

    

//InsMem

//InsMem insmem(pc, InsMemRw, Opcode, rs, rt, rd, sa, func, immediate, JumpAddr);

wire [31:0] Instruction;
wire IRwrite;
//wire [31:0] MemData;
Register IR(clk, IRwrite, Data_in, Instruction);
assign inst_out = Instruction;

assign Opcode = Instruction[31:26];  
assign rs = Instruction[25:21];  
assign rt = Instruction[20:16];  
assign rd = Instruction[15:11];  
assign immediate = Instruction[15:0];
assign sa = Instruction[10:6];
assign JumpAddr = Instruction[25:0];
assign func = Instruction[5:0];

//DataLate DR(clk, Data_in, MemData);

//controlUnit
wire AddrSrc;

controlUnit CU(Opcode, func, rt, zero, sign, clk, reset, InsMemRW, PCWre, ExtSel, DBDataSrc, mWR, mRD, WrRegData, RegDst, Load, 
                Store, ALUSrcA, ALUSrcB, PCSrc, ALUOp, state_out, RegWre, IRwrite, AddrSrc);
assign mem_w = mWR;       // mem_w output
assign state = state_out; // state output

//Mux RegDst
//assign rd_e = 27'b0 + rd;
//assign rt_e = 27'b0 + rt;

mux4 mux_RDst(32'h1F, {27'b0, rt}, {27'b0, rd}, 0, RegDst, out1_e);
//assign out1 = out1_e[4:0];

//DBDataSrc

assign MemDataOut = Data_in;    // Data_in input
mux2 DB_Src(result, MemDataOut, DBDataSrc, tempWrite);
DataLate MEMDR(clk, tempWrite, MEM_out);

//RF
RF regfile(clk, reset, RegWre, rs, rt, out1_e[4:0], writedata, Data1, Data2);
DataLate ADR(clk, Data1, ADR_out);
DataLate BDR(clk, Data2, BDR_out);

assign Data_out = BDR_out;      // Data_out output

//ALUSrcA, ALUSrcB
//assign sa_e = 27'b0 + sa;
mux4 ALU_A(ADR_out, {27'b0, sa}, 16, 0, ALUSrcA, DataA);
mux4 ALU_B(BDR_out, ExtOut, 0, 0, ALUSrcB, DataB);

//ALU
alu alu_x(DataA, DataB, ALUOp, result, zero, sign, clk);

DataLate ALUDR(clk, result, ALU_out); //暂时没有确定是否保留�

// 
wire [31:0] addr_out;
mux2 PC_or_DataAddr(pc, ALU_out, AddrSrc, addr_out);
assign Addr_out =  addr_out;    // Addr_out output

//DataMem

//DataMem datamem(ALU_out, Data2, Load, Store, mRD, mWR, MemDataOut);

//WrRegData

mux2 wrRegData(pc+4, MEM_out, WrRegData, writedata);

//Extended
EXT ext(immediate, ExtSel, ExtOut);

//NPC
NPC NPC_1(pc, PCSrc, JumpAddr, npc, Data1);
//PC
PC Pc(clk, reset, PCWre, npc, pc);

assign PC_out = pc; // PC_out output

endmodule
