module MEMWBREG(
    input clk,
    input rst,
    input MEM_Stall,
    input MEM_Flush,

    input[31:0] ALUResult_in,
    input[31:0] MemData_in,
    input[4:0] RegDstAdddr_in,
    output reg[31:0] ALUResult_o,
    output reg[31:0] MemData_o,
    output reg[4:0] RegDstAdddr_MEMWB,
    //Control
    input[1:0] MemtoReg_in,
    input RegWre_in,
    output reg[1:0] MemtoReg_o,
    output reg RegWre_MEMWB
);

initial
begin
    ALUResult_o <= 0;
    MemData_o <= 0;
    RegDstAdddr_MEMWB <= 0;
    MemtoReg_o <= 0;
    RegWre_MEMWB <= 0;
end

always @(posedge clk) begin
    if(rst)
    begin
        ALUResult_o <= 0;
        MemData_o <= 0;
        RegDstAdddr_MEMWB <= 0;
        MemtoReg_o <= 0;
        RegWre_MEMWB <= 0;
    end
    else if(!MEM_Stall)
    begin
        if(MEM_Flush)
        begin
            ALUResult_o <= 0;
            MemData_o <= 0;
            RegDstAdddr_MEMWB <= 0;
            MemtoReg_o <= 0;
            RegWre_MEMWB <= 0;
        end

        else
        begin
            ALUResult_o <= ALUResult_in;
            MemData_o <= MemData_in;
            RegDstAdddr_MEMWB <= RegDstAdddr_in;
            MemtoReg_o <= MemtoReg_in;
            RegWre_MEMWB <= RegWre_in;
        end
    end
end

endmodule // MEMWBREG