module EXMEMREG(
    input clk,
    input rst,
    input EX_Stall,
    input EX_Flush,
    //From EX
    input[31:0] PCPlus_in,
    input[31:0] ALUResult_in,
    input[31:0] MemWriteData_in,
    input[4:0] RegDstAddr_in,
    output reg[31:0] PCPlus_EXMEM,
    output reg[31:0] ALUResult_o,
    output reg[31:0] MemWriteData_o,
    output reg[4:0] RegDstAddr_EXMEM,

    //control
    input MemRead_in,
    input MemWrite_in,
    input[2:0] Load_in,
    input[1:0] Store_in,
    input[1:0] MemtoReg_in,
    input RegWrite_in,
    output reg MemRead_o,
    output reg MemWrite_o,
    output reg[2:0] Load_o,
    output reg[1:0] Store_o,
    output reg[1:0] MemtoReg_EXMEM,
    output reg RegWrite_EXMEM
);

initial
begin
    ALUResult_o <= 0;
    MemWriteData_o <= 0;
    RegDstAddr_EXMEM <= 0;
    MemRead_o <= 0;
    MemWrite_o <= 0;
    Load_o <= 0;
    Store_o <= 0;
    MemtoReg_EXMEM <= 0;
    RegWrite_EXMEM <= 0;
end

always @(posedge clk) begin
    if(rst)
    begin
        ALUResult_o <= 0;
        MemWriteData_o <= 0;
        RegDstAddr_EXMEM <= 0;
        MemRead_o <= 0;
        MemWrite_o <= 0;
        Load_o <= 0;
        Store_o <= 0;
        MemtoReg_EXMEM <= 0;
        RegWrite_EXMEM <= 0;
    end
    else if(!EX_Stall)
    begin
        if(EX_Flush)
        begin
            ALUResult_o <= 0;
            MemWriteData_o <= 0;
            RegDstAddr_EXMEM <= 0;
            MemRead_o <= 0;
            MemWrite_o <= 0;
            Load_o <= 0;
            Store_o <= 0;
            MemtoReg_EXMEM <= 0;
            RegWrite_EXMEM <= 0;
        end

        else
        begin
            ALUResult_o <= ALUResult_in;
            MemWriteData_o <= MemWriteData_in;
            RegDstAddr_EXMEM <= RegDstAddr_in;
            MemRead_o <= MemRead_in;
            MemWrite_o <= MemWrite_in;
            Load_o <= Load_in;
            Store_o <= Store_in;
            MemtoReg_EXMEM <= MemtoReg_in;
            RegWrite_EXMEM <= RegWrite_in;
        end
    end
end

endmodule // EXMEMREG