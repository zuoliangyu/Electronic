library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity STM32_OUT2 is
	generic (ADDRa:std_logic_vector(15 downto 0):=x"000a";
				ADDRb:std_logic_vector(15 downto 0):=x"000b");
	port(CS,RD,FLAG2 :in std_logic;
			ADDR :in std_logic_vector(15 downto 0);
			DB :out std_logic_vector(15 downto 0);
			AD_FIFO_DATA2 :in std_logic_vector(13 downto 0));
end;
architecture demo of STM32_OUT2 is
begin
	process(CS,RD,ADDR,FLAG2,AD_FIFO_DATA2)
	begin
		if CS='0' and RD='0' then
			case ADDR is
				when ADDRb=> if FLAG2='1' then DB<=x"0001";
								 else DB<=x"0000";end if;
				when ADDRa=> DB<="00" & AD_FIFO_DATA2;
				when others=> DB<="ZZZZZZZZZZZZZZZZ";
			end case;
		else DB<="ZZZZZZZZZZZZZZZZ";
		end if;
	end process;
end demo;