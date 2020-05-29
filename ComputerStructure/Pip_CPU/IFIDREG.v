module IFIDREG(
    input clk,
    input rst,
    input IF_Stall,
    input IF_Flush,
    input [31:0] Instruction_in,
    input [31:0] PCPlus4_in,
    output[31:0] Instruction_out,
    output[31:0] PCPlus4_out
);

initial
begin
    PCPlus4_out <= 32'b0;
    Instruction_out <= 32'b0;
end

always @(posedge clk) begin
    if(rst)
    begin
        PCPlus4_out <= 32'b0;
        Instruction_out <= 32'b0;
    end
    else if(!IF_Stall)
    begin
        if(IF_Flush)
        begin
            PCPlus4_out <= 32'b0;
            Instruction_out <= 32'b0;
        end
        else
        begin
            PCPlus4_out <= PCPlus4_in;
            Instruction_out <= Instruction_in;
        end
    end
end

endmodule // IFIDREG