module DataLate(input clk,
		input[31:0] i_data,
                output reg [31:0] o_data);
 
    always @(negedge clk) begin
        o_data = i_data;
    end
 
endmodule
