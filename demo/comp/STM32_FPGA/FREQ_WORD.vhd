LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_SIGNED.ALL;
ENTITY FREQ_WORD IS
	GENERIC (ADDR6:STD_LOGIC_VECTOR(15 DOWNTO 0):=X"0006";
	ADDR7:STD_LOGIC_VECTOR(15 DOWNTO 0):=X"0007");
	PORT(CS,WR: IN STD_LOGIC;
	DB:IN STD_LOGIC_VECTOR(15 downto 0);
	ADDR:IN STD_LOGIC_VECTOR(15 downto 0);
	OUTH,OUTL:OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
END ENTITY;
ARCHITECTURE BHV OF FREQ_WORD IS
BEGIN
	PROCESS(CS,WR,ADDR,DB)
	BEGIN
		IF CS='0' AND WR='0' THEN
			IF ADDR=ADDR6 THEN OUTH<=DB;
			ELSIF ADDR=ADDR7 THEN OUTL<=DB;
			END IF;
		END IF;
	END PROCESS;
END BHV;