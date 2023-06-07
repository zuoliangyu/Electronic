library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity CNT10 is
	port(CLK :in std_logic;
		  COUT:out std_logic_vector(9 downto 0));
end CNT10;
architecture demo of CNT10 is
begin
	process(CLK)
	variable CNT :std_logic_vector(9 downto 0);
	begin
		if CLK'EVENT AND CLK='1' then CNT:=CNT+'1';
		end if;
		COUT<= CNT;
	end process;
end demo;