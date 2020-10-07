`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:59:42 03/12/2019 
// Design Name: 
// Module Name:    adder_1bit 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module adder_1bit(
input a,
input b,
input ci,
output s,
output co
);

// Instantiate the module

wire s1, c1, c2, c3;
and 	(c1, a, b),
		(c2, b, ci),
		(c3, a, ci);
		
xor 	(s1, a, b),
		(s, s1, ci);
		
or	 (co, c1, c2, c3);

endmodule
