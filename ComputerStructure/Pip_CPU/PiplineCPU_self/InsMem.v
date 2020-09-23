module InsMem(input[31:0] PC, output reg[31:0] instruction);
reg[31:0] mem[255:0];  
    initial 
    begin
        //$readmemh("mipstestloopjal_sim.txt", mem);
         $readmemh("miptest_branch.txt", mem);
        //$readmemh("mipstest_extloop.txt", mem);
        //$readmemh("extendedtest.txt", mem);
    end
    always@(*)
    begin
        assign instruction = mem[PC>>2];
    end
endmodule