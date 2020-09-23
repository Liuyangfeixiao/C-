`include "ctrl_encode_def.v"

module alu(clk, A, B, ALUOp, C, Zero);
           
   input  signed [31:0] A, B;
   input         [3:0]  ALUOp;
   input clk;
   output signed [31:0] C;
   output Zero;
   //output Sign;
   
   reg [31:0] C;
   integer    i;
       
   always @(*) begin
      case ( ALUOp )
          `ALU_NOP:  C = A;                          // NOP
          `ALU_ADD:  C = A + B;                      // ADD
          `ALU_SUB:  C = A - B;                      // SUB
          `ALU_AND:  C = A & B;                      // AND/ANDI
          `ALU_OR:   C = A | B;                      // OR/ORI
          `ALU_SLT:  
		begin
		C = (A < B) ? 32'd1 : 32'd0;    // SLT/SLTI
		end
	  `ALU_SLTR: C = (B < A)? 32'd1 : 32'd0;     // STL REVERSE
          `ALU_SLTU: C = ({1'b0, A} < {1'b0, B}) ? 32'd1 : 32'd0;
	  `ALU_XOR:  C = A ^ B;			     // XOR/XORI
	  `ALU_NOR:  C = ~(A | B);		     // NOR
	  `ALU_SLL:  C = B << A;		     // SLL/SLLV / LUI
	  `ALU_SRA:  C = $signed(B) >>> A;	 // SRA/SRAV
	  `ALU_SRL:  C = B >> A;		     // SRL/SRLV
	  
          default:   C = A;                          // Undefined
      endcase
   end // end always
   
   assign Zero = (C == 32'b0);

endmodule
    