library verilog;
use verilog.vl_types.all;
entity CNT32_vlg_sample_tst is
    port(
        CLK             : in     vl_logic;
        CLKBASE         : in     vl_logic;
        CLKBASEEN       : in     vl_logic;
        CLKEN           : in     vl_logic;
        CLR             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end CNT32_vlg_sample_tst;
