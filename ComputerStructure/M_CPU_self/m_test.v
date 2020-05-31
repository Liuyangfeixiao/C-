`timescale 1ns / 1ps 

module m_test;
reg clk;
reg reset;
    wire[3:0] state_out;
    wire[5:0] Opcode;
    wire[5:0] func;
    wire[31:0] Data1;
    wire[31:0] Data2;
    wire[31:0] DataA;
    wire[31:0] DataB;
    wire[31:0] tempWrite;
    wire[31:0] writedata;
    wire[31:0] pc;
    wire[31:0] npc;
    wire[31:0] result;
    wire[4:0] rs;
    wire[4:0] rt;
    wire[31:0] DataOut;


m_cpu uut(.clk(clk),
        .reset(reset),
	.state_out(state_out),
        .Opcode(Opcode),
	.func(func),
        .Data1(Data1),
        .Data2(Data2),
	.DataA(DataA),
	.DataB(DataB),
	.tempWrite(tempWrite),
	.writedata(writedata),
        .pc(pc),
	.npc(npc),
        .result(result),
        .rs(rs),
        .rt(rt),
        .DataOut(DataOut));

 initial
        begin
            // Initialize Inputs
            clk = 0;
            reset = 1;
            // Wait 100 ns for global reset finish
            #50
            reset = 0;

        end

        always
            begin
            #20;
            clk = ~clk;
            end
endmodule
