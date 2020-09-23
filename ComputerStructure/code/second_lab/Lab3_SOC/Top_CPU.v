module Top_CPU(
input RSTN,
input [3:0] BTN_y,
input [15:0] SW,
input clk_100mhz,
output [4:0] BTN_x,
output CR,
output RDY,
output readn,
output seg_clk,
output seg_sout,
output SEG_PEN,
output seg_clrn,
output led_clk,
output led_sout,
output LED_PEN,
output led_clrn
)

wire [31:0] inst;
wire [31:0] PC;

wire [4:0] Key_out;
wire [3:0] Pulse;
wire [3:0] BTN_OK;
wire [15:0] SW_OK;
wire rst;
wire Clk_CPU;
wire [31:0] Div;
wire Mem_w;
wire [31:0] Addr_out;
wire [31:0] Data_in;
wire [31:0] Data_out;
wire [31:0] ram_data_in;
wire data_ram_we;
wire [9:0] ram_addr;
wire [31:0] ram_data_out;

wire [31:0] Ai;
wire [31:0] Bi;
wire [7:0] blink;
wire IO_clk;
wire [31:0] CPU2IO;
wire GPIOE0;
wire GPIOF0;
wire [15:0] LED_out;
wire [31:0] Counter_out;
wire [2:0] Counter_set;
wire Counter2_out
wire Counter1_out;
wire Counter0_out;
wire Counter_we;

wire [7:0] LE_out;
wire [7:0] point_out;
wire [31:0] Disp_num;




SCPU U1(.clk(Clk_CPU),			
        .reset(rst),
        .MIO_ready(),   // /???????
                        
        .inst_in(inst),
        .Data_in(Data_in),	
                        
        .mem_w(Mem_w),
        .PC_out(PC),
        .Addr_out(Addr_out),
        .Data_out(Data_out), 
        .CPU_MIO(), // ?????????
        .INT(Counter0_out)
        );

ROM_D U2(.a(PC[11:2]),
         .spo(inst)
         );

RAM_B U3(.addra(ram_addr), 
         .wea(data_ram_we),
         .dina(ram_data_in),
         .clka(clk_100mhz),
         .douta(ram_data_out)
        );

MIO_BUS_IO U4(.clk(clk_100mhz),
                .rst(rst),
                .BTN(BTN_OK),
                .SW(SW_OK),
                .mem_w(Mem_w),
                .Cpu_data2bus(Data_out),				//data from CPU
                .addr_bus(Addr_out),
                .ram_data_out(ram_data_out),
                .led_out(LED_out),
                .counter_out(Counter_out),
                .counter0_out(Counter0_out),
                .counter1_out(Counter1_out),
                .counter2_out(Counter2_out),
                
                .Cpu_data4bus(Data_in),				//write to CPU
                .ram_data_in(ram_data_in),				//from CPU write to Memory
                .ram_addr(ram_addr),						//Memory Address signals
                .data_ram_we(data_ram_we),
                .GPIOf0000000_we(GPIOF0),
                .GPIOe0000000_we(GPIOE0),
                .counter_we(Counter_we),
                .Peripheral_in(CPU2IO)
                );

SEnter_2_32_IO M4(.clk(clk_100mhz),
                    .BTN(BTN_OK[2:0]),				//��ӦSAnti_jitter�а���
                    .Ctrl({SW_OK[7:5], SW_OK[15], SW_OK[0]}),				//{SW[7:5],SW[15],SW[0]}
                    .D_ready(RDY),					//��ӦSAnti_jitterɨ������Ч
                    .Din(Key_out),
                    .readn(readn), 			//=0��ɨ����
                    .Ai(32'h87654321),	//����32λ��һ��Ai
                    .Bi(32'h12345678),	//����32λ������Bi
                    .blink(blink)				//��������ָʾ
                    );

assign IO_clk = ~Clk_CPU;

Multi_8CH32_IO U5(.clk(IO_clk),
                    .rst(rst),
                    .EN(GPIOE0),								//Write EN
                    .Test(SW_OK[7:5]),						//ALU&Clock,SW[7:5]	
                    .point_in({Div[31:0], Div[31:0]}),					//����8λ��ʾ������8��С����
                    .LES(64{1'b0}),					//����8λ��ʾ������8����˸λ
                    .Data0(CPU2IO),					//disp_cpudata
                    .data1({2'b00, PC[31:2]}),
                    .data2(inst),
                    .data3(Counter_out),
                    .data4(Addr_out),
                    .data5(Data_out),
                    .data6(Data_in),
                    .data7(PC),
                    .point_out(point_out),
                    .LE_out(LE_out),
                    .Disp_num(Disp_num)
                    );

SSeg7_Dev_IO U6(.clk(clk_100mhz),			//	ʱ��
                .rst(rst),			//��λ
                .Start(Div[20]),		//����ɨ������
                .SW0(SW_OK[0]),			//�ı�(16����)/ͼ��(����)�л�
                .flash(Div[25]),		//�߶�����˸Ƶ��
                .Hexs(Disp_num),	//32λ����ʾ��������
                .point(point_out),	//�߶���С���㣺8��
                .LES(LE_out),		//�߶���ʹ�ܣ�=1ʱ��˸
                .seg_clk(seg_clk),	//������λʱ��
                .seg_sout(seg_sout),	//�߶���ʾ����(��������)
                .SEG_PEN(SEG_PEN),	//�߶�����ʾˢ��ʹ��
                .seg_clrn(seg_clrn)	//�߶�����ʾ����
                );

SPIO_IO U7(.clk(IO_clk),							//ʱ��
            .rst(rst),                    //��λ
            .Start(Div[20]),                  //����ɨ������
            .EN(GPIOF0),                     //PIO/LED��ʾˢ��ʹ��
            .P_Data(CPU2IO),          //�������룬���ڴ�����������
            .counter_set(Counter_set),  //���ڼ���/��ʱģ�����ƣ���ʵ�鲻��
            .LED_out(LED_out),        //������������
            .led_clk(led_clk),          //������λʱ��
            .led_sout(led_sout),         //��������
            .led_clrn(led_clrn),         //LED��ʾ����
            .LED_PEN(LED_PEN),          //LED��ʾˢ��ʹ��
            .GPIOf0()                   // ???????
            );

clk_div U8(.clk(clk_100mhz),
            .rst(rst),
            .SW2(SW_OK[2]),
            .clkdiv(Div),
            .Clk_CPU(Clk_CPU)
            );

SAnti_jitter_IO U9(.clk(clk_100mhz), 
                    .RSTN(RSTN),
                    .readn(readn),      //????
                    .Key_y(BTN_y),
                    .Key_x(BTN_x),
                    .SW(SW), 
                    .Key_out(Key_out),
                    .Key_ready(RDY),
                    .pulse_out(Pulse),
                    .BTN_OK(BTN_OK),
                    .SW_OK(SW_OK),
                    .CR(CR),
                    .rst(rst)
                    );

Counter_3_IO U10(.clk(IO_clk),
                .rst(rst),
                .clk0(Div[6]),
                .clk1(Div[9]),
                .clk2(Div[11]),
                .counter_we(Div[11]),
                .counter_val(CPU2IO),
                .counter_ch(Counter_set),				//Counter channel set

                .counter0_OUT(Counter0_out),
                .counter1_OUT(Counter1_out),
                .counter2_OUT(Counter2_out),
                .counter_out(Counter_out)
                );




endmodule