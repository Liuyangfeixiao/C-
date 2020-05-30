module IDEXREG(
    input clk,
    input rst,
    input ID_Stall,
    input ID_Flush, //flush for stall or start
    input[31:0] PCPlus_in,
    input[31:0] ReadData1_i,
    input[31:0] ReadData2_i,
    //change to the Immdiate?
    input[31:0] ImmExtended_in,
    //input[31:0] ImmZeroExtend_in,
    input[31:0] SamZeroExtend_in,
    input[4:0] Rs_in,
    input[4:0] Rt_in,
    input[4:0] Rd_in,
    output reg[31:0] PCPlus_IDEX,
    output reg[31:0] ReadData1_o,
    output reg[31:0] ReadData2_o,
    output reg[31:0] ImmExtended_o,
    //output reg[31:0] ImmZeroExtend_o,
    output reg[31:0] SamZeroExtend_o,
    output reg[4:0] Rs_IDEX,
    output reg[4:0] Rt_IDEX,
    output reg[4:0] Rd_IDEX,

    //control
    //input EXsel_in,
    input[1:0] RegDst_in,
    input[1:0] ALUSrcA_in,
    input[1:0] ALUSrcB_in,
    input[3:0] ALUOp_in,
    input MemRead_in,
    input MemWrite_in,
    input[2:0] Load_in,
    input[1:0] Store_in,
    input[1:0] MemtoReg_in,
    input RegWrite_in,
    //output reg EXsel_out,
    output reg[1:0] RegDst_out,
    output reg[1:0] ALUSrcA_out,
    output reg[1:0] ALUSrcB_out,
    output reg[3:0] ALUOp_out,
    output reg MemRead_IDEX,
    output reg MemWrite_IDEX,
    output reg[2:0] Load_out,
    output reg[1:0] Store_out,
    output reg[1:0] MemtoReg_out,
    output reg RegWrite_IDEX
    );
initial
begin
    PCPlus_IDEX <= 32'b0;
    ReadData1_o <= 32'b0;
    ReadData2_o <= 32'b0;
    ImmExtended_o <= 32'b0;
    SamZeroExtend_o <= 32'b0;
    Rs_IDEX <= 5'b0;
    Rt_IDEX <= 5'b0;
    Rd_IDEX <= 5'b0;
    RegDst_out <= 2'b00;
    ALUSrcA_out <= 2'b00;
    ALUSrcB_out <= 2'b00;
    ALUOp_out <= 4'b0;
    MemRead_IDEX <= 0;
    MemWrite_IDEX <= 0;
    Load_out <= 3'b000;
    Store_out <= 2'b00;
    MemtoReg_out <= 2'b00;
    RegWrite_IDEX <= 0;
end   

always @(posedge clk) begin
    if (rst) begin
    PCPlus_IDEX <= 32'b0;
    ReadData1_o <= 32'b0;
    ReadData2_o <= 32'b0;
    ImmExtended_o <= 32'b0;
    SamZeroExtend_o <= 32'b0;
    Rs_IDEX <= 5'b0;
    Rt_IDEX <= 5'b0;
    Rd_IDEX <= 5'b0;
    RegDst_out <= 2'b00;
    ALUSrcA_out <= 2'b00;
    ALUSrcB_out <= 2'b00;
    ALUOp_out <= 4'b0;
    MemRead_IDEX <= 0;
    MemWrite_IDEX <= 0;
    Load_out <= 3'b000;
    Store_out <= 2'b00;
    MemtoReg_out <= 2'b00;
    RegWrite_IDEX <= 0;
    end
    else if(!ID_Stall)
    begin
        if(ID_Flush)
        begin
            PCPlus_IDEX <= 32'b0;
            ReadData1_o <= 32'b0;
            ReadData2_o <= 32'b0;
            ImmExtended_o <= 32'b0;
            SamZeroExtend_o <= 32'b0;
            Rs_IDEX <= 5'b0;
            Rt_IDEX <= 5'b0;
            Rd_IDEX <= 5'b0;
            RegDst_out <= 2'b00;
            ALUSrcA_out <= 2'b00;
            ALUSrcB_out <= 2'b00;
            ALUOp_out <= 4'b0;
            MemRead_IDEX <= 0;
            MemWrite_IDEX <= 0;
            Load_out <= 3'b000;
            Store_out <= 2'b00;
            MemtoReg_out <= 2'b00;
            RegWrite_IDEX <= 0;
        end
        else
        begin
            PCPlus_IDEX <= PCPlus_in;
            ReadData1_o <= ReadData1_i;
            ReadData2_o <= ReadData2_i;
            ImmExtended_o <= ImmExtended_in;
            SamZeroExtend_o <= SamZeroExtend_in;
            Rs_IDEX <= Rs_in;
            Rt_IDEX <= Rt_in;
            Rd_IDEX <= Rd_in;
            RegDst_out <= RegDst_in;
            ALUSrcA_out <= ALUSrcA_in;
            ALUSrcB_out <= ALUSrcB_in;
            ALUOp_out <= ALUOp_in;
            MemRead_IDEX <= MemRead_in;
            MemWrite_IDEX <= MemWrite_in;
            Load_out <= Load_in;
            Store_out <= Store_in;
            MemtoReg_out <= MemtoReg_in;
            RegWrite_IDEX <= RegWrite_in;
        end
    end
end


endmodule // IDEXREG