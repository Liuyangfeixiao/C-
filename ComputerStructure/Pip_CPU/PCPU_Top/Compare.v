module Compare(
    input signed [31:0] A,
    input signed [31:0] B,
    output reg [1:0] res
);
always @(*) begin
    if (A < B) begin
        res = 2'b00;
    end
    else if(A == B)
        res = 2'b01;
    else
        res = 2'b10;
end


endmodule // Compare