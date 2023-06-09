LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
ENTITY DA_IN IS
	PORT(
	--CLK:IN STD_LOGIC;
	AD_FIFO_DATA:IN STD_LOGIC_VECTOR(13 downto 0);
	DA_DATA_IN:OUT STD_LOGIC_VECTOR(9 DOWNTO 0)
	);
END ENTITY;
ARCHITECTURE BHV OF DA_IN IS
BEGIN
	PROCESS(AD_FIFO_DATA)
	BEGIN
	--IF CLK'EVENT AND CLK='1' THEN
	DA_DATA_IN(9 DOWNTO 0)<=AD_FIFO_DATA(13 DOWNTO 4);
	--END IF;
	END PROCESS;
END BHV;