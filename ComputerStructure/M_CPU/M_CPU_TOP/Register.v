module Register (
    input clk,
    input signal,
    input [31:0] in,
    output reg [31:0] out
);

always @(negedge clk) begin
    out <= (signal == 1) ? in : out;
end
    
endmodule