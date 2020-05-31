module PC(clk, rst, NPC, PC, PCWre);
input clk;
input rst;
input PCWre;
input[31:0] NPC;
output reg[31:0] PC;
initial
begin
    PC <= 32'b0;
end

always @(posedge clk, posedge rst)
begin
    if(rst)
        PC <= 32'b0;
    else
        begin
            if(PCWre)
                PC <= NPC;
            else
                PC <= PC;
        end
end

endmodule