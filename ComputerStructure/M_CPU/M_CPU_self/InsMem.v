
module InsMem(
    input[31:0] IAddr,
    input InsMemRW,
    output[5:0] op,
    output[4:0] rs,
    output[4:0] rt,
    output[4:0] rd,
    output[4:0] sa,
    output[5:0] func,
    output[15:0] imd,
    output[25:0] JumpAddr

);

//reg [31:0] mem[1023:0];
reg [7:0] mem[1023:0];
reg [31:0] instruction;
initial begin
$readmemh("C:\\Users\\HP\\Desktop\\Markdown\\TestCode\\mipstestloop_sim.dat", mem);
instruction = 0;
end 

always @(IAddr or InsMemRW)
begin
 
    //begin
	instruction[7:0] = mem[IAddr+3];
	instruction[15:8] = mem[IAddr + 2];
	instruction[23:16] = mem[IAddr + 1];
	instruction[31:24] = mem[IAddr];
	//instruction = mem[IAddr>>2];
    //end
end
    assign op = instruction[31:26];  
    assign rs = instruction[25:21];  
    assign rt = instruction[20:16];  
    assign rd = instruction[15:11];  
    assign imd = instruction[15:0];
    assign sa = instruction[10:6];
    assign JumpAddr = instruction[25:0];
    assign func = instruction[5:0];

endmodule 