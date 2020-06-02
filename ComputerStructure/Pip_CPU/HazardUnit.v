module HazardUnit(
    input[5:0] Opcode_IFID,
    input[5:0] Func_IFID,
    input[4:0] RsAddr_IFID,
    input[4:0] RtAddr_IFID,
    input[4:0] RtAddr_IDEX,
    input[4:0] RegWriteAddr_IDEX,
    input[4:0] RtAddr_EXMEM,
    input RegWrite_IDEX,
    input RegWrite_EXMEM,
    input MemRd_EXMEM,
    input MemRd_IDEX,
    //output reg IFID_Flush,
    output reg IFID_Stall,
    output reg PCWre,
    output reg IDEX_Flush); //maybe there is PCSrc, NextType to hazard the Branch 
initial
begin
    PCWre <= 1;
    //IFID_Flush <= 0;
    IFID_Stall <= 0;
    IDEX_Flush <= 0;

end
always @(*) begin
    if(MemRd_IDEX && (RtAddr_IDEX == RsAddr_IFID || RtAddr_IDEX == RtAddr_IFID)) //lw hazard
    begin
        IFID_Stall = 1;
        //IFID_Flush = 1;
        IDEX_Flush = 1;
        PCWre = 0;
        $display("A Load hazard occur");
    end

   else if (MemRd_EXMEM && (RtAddr_EXMEM == RsAddr_IFID || RtAddr_EXMEM == RtAddr_IFID) && (Opcode_IFID == 6'h04 || Opcode_IFID == 6'h05 )) begin
        IFID_Stall = 1;
        //IFID_Flush = 0;
        IDEX_Flush = 1;
        PCWre = 0;
        $display("A hazard for beq or bnq occur");
    end

   else if (MemRd_EXMEM && (RtAddr_EXMEM == RsAddr_IFID) && (Opcode_IFID == 6'h01 || Opcode_IFID == 6'h06 || Opcode_IFID == 6'h07)) begin
        IFID_Stall = 1;
        //IFID_Flush = 0;
        IDEX_Flush = 1;
        PCWre = 0;
        $display("A hazard for blez, bltz, bgez, bgtz occur");
    end
    else if(RegWrite_IDEX && (RegWriteAddr_IDEX == RsAddr_IFID) && (Opcode_IFID == 6'h00 && (Func_IFID == 6'd8 || Func_IFID == 6'd9))) begin
 	IFID_Stall = 1;
        //IFID_Flush = 0;
        IDEX_Flush = 1;
        PCWre = 0;
        $display("A hazard for jr, jalr occur");   
    end
    else if(RegWrite_EXMEM && (RtAddr_EXMEM == RsAddr_IFID) && (Opcode_IFID == 6'h00 && (Func_IFID == 6'd8 || Func_IFID == 6'd9))) begin
     	IFID_Stall = 1;
        //IFID_Flush = 0;
        IDEX_Flush = 1;
        PCWre = 0;
        $display("A hazard for jr, jalr occur");
    end
    else begin
    PCWre = 1;
    //IFID_Flush <= 0;
    IFID_Stall = 0;
    IDEX_Flush = 0;
    end
    
        
end

endmodule // HazardUnit