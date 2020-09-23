module PC( clk, rst, PCWre, NPC, PC );

  input              clk;
  input              rst;
  input		     PCWre;
  input       [31:0] NPC;
  output reg  [31:0] PC;

  always @(PCWre or posedge rst)
    if (rst) 
      PC <= 32'h0000_0000;
//      PC <= 32'h0000_3000;
    else 
	begin
	if(PCWre)
      	    PC <= NPC;
	else
	    PC <= PC;
	end
      
endmodule

