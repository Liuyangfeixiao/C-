`timescale 1ns / 1ps

module PCPU_TEST();
reg clk;
reg rst;

pipeline_CPU uut(clk, rst);

initial
begin
    clk = 0;
    rst = 1;
    #50
    rst = 0;
end

always begin
    #20;
    clk = ~clk;
end
endmodule // PCPU_TEST