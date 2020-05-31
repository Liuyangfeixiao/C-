module DataMem(
    input[31:0] DAddr,
    input[31:0] DataIn,
    input[2:0] Load,
    input[1:0] Store,
    input mRD,
    input mWR,
    output reg[31:0] DataOut
);

reg [31:0] temp;
reg [31:0] temp_mem;
initial begin
        DataOut <= 0;
end

reg [7:0] memory[1023:0];
    integer i;

    initial
        begin
            for(i = 0; i < 32; i=i+1)
                memory [i] <= 0;
        end


always @(mRD or mWR)
begin
     if (mRD)
        begin
          temp [31:24] = memory [DAddr+3];
          temp [23:16] = memory [DAddr+2];
          temp [15:8] = memory [DAddr+1];
          temp [7:0] = memory [DAddr];   
          case(Load)
		3'b000: DataOut = {{24{temp[7]}}, temp[7:0]};
		3'b001: DataOut = {24'b0, temp[7:0]};
		3'b010: DataOut = {{16{temp[15]}}, temp[15:0]};
		3'b011: DataOut = {16'b0, temp[15:0]};
		3'b100: DataOut = temp;
		default: DataOut = temp;
	  endcase      
	end

     else if(mWR)
	begin
	  case(Store)
		2'b00: memory[DAddr] = DataIn[7:0];//temp_mem = {{24{DataIn[7]}}, DataIn[7:0]};
		2'b01: 
		    begin
			memory[DAddr] = DataIn[7:0];
			memory[DAddr+1] = DataIn[15:8];
		    end		//temp_mem = {{16{DataIn[15]}}, DataIn[15:0]};
		2'b10: 
		    begin
			memory [DAddr+3] = DataIn [31:24];
          		memory [DAddr+2] = DataIn [23:16];
          		memory [DAddr+1] = DataIn [15:8];
          		memory [DAddr] = DataIn [7:0];
		    end		//temp_mem = DataIn;
		default: 
		    begin
			memory [DAddr+3] = DataIn [31:24];
          		memory [DAddr+2] = DataIn [23:16];
          		memory [DAddr+1] = DataIn [15:8];
          		memory [DAddr] = DataIn [7:0];
		    end		//temp_mem = DataIn;
	  endcase
          DataOut <= 0;
	end

end



endmodule 