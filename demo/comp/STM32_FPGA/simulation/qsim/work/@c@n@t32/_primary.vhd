library verilog;
use verilog.vl_types.all;
entity CNT32 is
    port(
        CLR             : in     vl_logic;
        CLK             : in     vl_logic;
        CLKBASE         : in     vl_logic;
        CLKEN           : in     vl_logic;
        CLKBASEEN       : in     vl_logic;
        Q               : out    vl_logic_vector(31 downto 0);
        QBASE           : out    vl_logic_vector(31 downto 0)
    );
end CNT32;
