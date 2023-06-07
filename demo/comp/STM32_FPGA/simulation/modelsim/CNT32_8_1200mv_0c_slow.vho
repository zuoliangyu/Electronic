-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Full Version"

-- DATE "08/04/2020 15:58:05"

-- 
-- Device: Altera EP4CE6E22C8 Package TQFP144
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	CNT32 IS
    PORT (
	CLR : IN std_logic;
	CLK : IN std_logic;
	CLKBASE : IN std_logic;
	CLKEN : IN std_logic;
	CLKBASEEN : IN std_logic;
	Q : OUT std_logic_vector(31 DOWNTO 0);
	QBASE : OUT std_logic_vector(31 DOWNTO 0)
	);
END CNT32;

-- Design Ports Information
-- Q[0]	=>  Location: PIN_55,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[1]	=>  Location: PIN_76,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[2]	=>  Location: PIN_67,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[3]	=>  Location: PIN_60,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[4]	=>  Location: PIN_65,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[5]	=>  Location: PIN_100,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[6]	=>  Location: PIN_84,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[7]	=>  Location: PIN_98,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[8]	=>  Location: PIN_80,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[9]	=>  Location: PIN_77,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[10]	=>  Location: PIN_86,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[11]	=>  Location: PIN_99,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[12]	=>  Location: PIN_85,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[13]	=>  Location: PIN_83,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[14]	=>  Location: PIN_104,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[15]	=>  Location: PIN_87,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[16]	=>  Location: PIN_74,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[17]	=>  Location: PIN_51,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[18]	=>  Location: PIN_59,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[19]	=>  Location: PIN_68,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[20]	=>  Location: PIN_52,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[21]	=>  Location: PIN_66,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[22]	=>  Location: PIN_53,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[23]	=>  Location: PIN_75,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[24]	=>  Location: PIN_64,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[25]	=>  Location: PIN_69,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[26]	=>  Location: PIN_54,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[27]	=>  Location: PIN_73,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[28]	=>  Location: PIN_70,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[29]	=>  Location: PIN_58,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[30]	=>  Location: PIN_72,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[31]	=>  Location: PIN_71,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[0]	=>  Location: PIN_137,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[1]	=>  Location: PIN_133,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[2]	=>  Location: PIN_28,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[3]	=>  Location: PIN_138,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[4]	=>  Location: PIN_128,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[5]	=>  Location: PIN_129,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[6]	=>  Location: PIN_3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[7]	=>  Location: PIN_143,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[8]	=>  Location: PIN_2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[9]	=>  Location: PIN_115,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[10]	=>  Location: PIN_142,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[11]	=>  Location: PIN_1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[12]	=>  Location: PIN_141,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[13]	=>  Location: PIN_135,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[14]	=>  Location: PIN_136,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[15]	=>  Location: PIN_132,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[16]	=>  Location: PIN_10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[17]	=>  Location: PIN_33,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[18]	=>  Location: PIN_144,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[19]	=>  Location: PIN_120,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[20]	=>  Location: PIN_32,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[21]	=>  Location: PIN_124,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[22]	=>  Location: PIN_46,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[23]	=>  Location: PIN_31,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[24]	=>  Location: PIN_121,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[25]	=>  Location: PIN_119,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[26]	=>  Location: PIN_30,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[27]	=>  Location: PIN_127,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[28]	=>  Location: PIN_7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[29]	=>  Location: PIN_11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[30]	=>  Location: PIN_126,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- QBASE[31]	=>  Location: PIN_125,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLK	=>  Location: PIN_24,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLR	=>  Location: PIN_25,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLKEN	=>  Location: PIN_111,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLKBASEEN	=>  Location: PIN_106,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLKBASE	=>  Location: PIN_23,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF CNT32 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_CLR : std_logic;
SIGNAL ww_CLK : std_logic;
SIGNAL ww_CLKBASE : std_logic;
SIGNAL ww_CLKEN : std_logic;
SIGNAL ww_CLKBASEEN : std_logic;
SIGNAL ww_Q : std_logic_vector(31 DOWNTO 0);
SIGNAL ww_QBASE : std_logic_vector(31 DOWNTO 0);
SIGNAL \CLR~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \CLK~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \CLKBASE~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \Q[0]~output_o\ : std_logic;
SIGNAL \Q[1]~output_o\ : std_logic;
SIGNAL \Q[2]~output_o\ : std_logic;
SIGNAL \Q[3]~output_o\ : std_logic;
SIGNAL \Q[4]~output_o\ : std_logic;
SIGNAL \Q[5]~output_o\ : std_logic;
SIGNAL \Q[6]~output_o\ : std_logic;
SIGNAL \Q[7]~output_o\ : std_logic;
SIGNAL \Q[8]~output_o\ : std_logic;
SIGNAL \Q[9]~output_o\ : std_logic;
SIGNAL \Q[10]~output_o\ : std_logic;
SIGNAL \Q[11]~output_o\ : std_logic;
SIGNAL \Q[12]~output_o\ : std_logic;
SIGNAL \Q[13]~output_o\ : std_logic;
SIGNAL \Q[14]~output_o\ : std_logic;
SIGNAL \Q[15]~output_o\ : std_logic;
SIGNAL \Q[16]~output_o\ : std_logic;
SIGNAL \Q[17]~output_o\ : std_logic;
SIGNAL \Q[18]~output_o\ : std_logic;
SIGNAL \Q[19]~output_o\ : std_logic;
SIGNAL \Q[20]~output_o\ : std_logic;
SIGNAL \Q[21]~output_o\ : std_logic;
SIGNAL \Q[22]~output_o\ : std_logic;
SIGNAL \Q[23]~output_o\ : std_logic;
SIGNAL \Q[24]~output_o\ : std_logic;
SIGNAL \Q[25]~output_o\ : std_logic;
SIGNAL \Q[26]~output_o\ : std_logic;
SIGNAL \Q[27]~output_o\ : std_logic;
SIGNAL \Q[28]~output_o\ : std_logic;
SIGNAL \Q[29]~output_o\ : std_logic;
SIGNAL \Q[30]~output_o\ : std_logic;
SIGNAL \Q[31]~output_o\ : std_logic;
SIGNAL \QBASE[0]~output_o\ : std_logic;
SIGNAL \QBASE[1]~output_o\ : std_logic;
SIGNAL \QBASE[2]~output_o\ : std_logic;
SIGNAL \QBASE[3]~output_o\ : std_logic;
SIGNAL \QBASE[4]~output_o\ : std_logic;
SIGNAL \QBASE[5]~output_o\ : std_logic;
SIGNAL \QBASE[6]~output_o\ : std_logic;
SIGNAL \QBASE[7]~output_o\ : std_logic;
SIGNAL \QBASE[8]~output_o\ : std_logic;
SIGNAL \QBASE[9]~output_o\ : std_logic;
SIGNAL \QBASE[10]~output_o\ : std_logic;
SIGNAL \QBASE[11]~output_o\ : std_logic;
SIGNAL \QBASE[12]~output_o\ : std_logic;
SIGNAL \QBASE[13]~output_o\ : std_logic;
SIGNAL \QBASE[14]~output_o\ : std_logic;
SIGNAL \QBASE[15]~output_o\ : std_logic;
SIGNAL \QBASE[16]~output_o\ : std_logic;
SIGNAL \QBASE[17]~output_o\ : std_logic;
SIGNAL \QBASE[18]~output_o\ : std_logic;
SIGNAL \QBASE[19]~output_o\ : std_logic;
SIGNAL \QBASE[20]~output_o\ : std_logic;
SIGNAL \QBASE[21]~output_o\ : std_logic;
SIGNAL \QBASE[22]~output_o\ : std_logic;
SIGNAL \QBASE[23]~output_o\ : std_logic;
SIGNAL \QBASE[24]~output_o\ : std_logic;
SIGNAL \QBASE[25]~output_o\ : std_logic;
SIGNAL \QBASE[26]~output_o\ : std_logic;
SIGNAL \QBASE[27]~output_o\ : std_logic;
SIGNAL \QBASE[28]~output_o\ : std_logic;
SIGNAL \QBASE[29]~output_o\ : std_logic;
SIGNAL \QBASE[30]~output_o\ : std_logic;
SIGNAL \QBASE[31]~output_o\ : std_logic;
SIGNAL \CLK~input_o\ : std_logic;
SIGNAL \CLK~inputclkctrl_outclk\ : std_logic;
SIGNAL \A:Q1[0]~1_combout\ : std_logic;
SIGNAL \CLR~input_o\ : std_logic;
SIGNAL \CLR~inputclkctrl_outclk\ : std_logic;
SIGNAL \CLKEN~input_o\ : std_logic;
SIGNAL \CLKBASEEN~input_o\ : std_logic;
SIGNAL \A:Q1[0]~0_combout\ : std_logic;
SIGNAL \A:Q1[0]~q\ : std_logic;
SIGNAL \A:Q1[1]~1_combout\ : std_logic;
SIGNAL \A:Q1[1]~q\ : std_logic;
SIGNAL \A:Q1[1]~2\ : std_logic;
SIGNAL \A:Q1[2]~1_combout\ : std_logic;
SIGNAL \A:Q1[2]~q\ : std_logic;
SIGNAL \A:Q1[2]~2\ : std_logic;
SIGNAL \A:Q1[3]~1_combout\ : std_logic;
SIGNAL \A:Q1[3]~q\ : std_logic;
SIGNAL \A:Q1[3]~2\ : std_logic;
SIGNAL \A:Q1[4]~1_combout\ : std_logic;
SIGNAL \A:Q1[4]~q\ : std_logic;
SIGNAL \A:Q1[4]~2\ : std_logic;
SIGNAL \A:Q1[5]~1_combout\ : std_logic;
SIGNAL \A:Q1[5]~q\ : std_logic;
SIGNAL \A:Q1[5]~2\ : std_logic;
SIGNAL \A:Q1[6]~1_combout\ : std_logic;
SIGNAL \A:Q1[6]~q\ : std_logic;
SIGNAL \A:Q1[6]~2\ : std_logic;
SIGNAL \A:Q1[7]~1_combout\ : std_logic;
SIGNAL \A:Q1[7]~q\ : std_logic;
SIGNAL \A:Q1[7]~2\ : std_logic;
SIGNAL \A:Q1[8]~1_combout\ : std_logic;
SIGNAL \A:Q1[8]~q\ : std_logic;
SIGNAL \A:Q1[8]~2\ : std_logic;
SIGNAL \A:Q1[9]~1_combout\ : std_logic;
SIGNAL \A:Q1[9]~q\ : std_logic;
SIGNAL \A:Q1[9]~2\ : std_logic;
SIGNAL \A:Q1[10]~1_combout\ : std_logic;
SIGNAL \A:Q1[10]~q\ : std_logic;
SIGNAL \A:Q1[10]~2\ : std_logic;
SIGNAL \A:Q1[11]~1_combout\ : std_logic;
SIGNAL \A:Q1[11]~q\ : std_logic;
SIGNAL \A:Q1[11]~2\ : std_logic;
SIGNAL \A:Q1[12]~1_combout\ : std_logic;
SIGNAL \A:Q1[12]~q\ : std_logic;
SIGNAL \A:Q1[12]~2\ : std_logic;
SIGNAL \A:Q1[13]~1_combout\ : std_logic;
SIGNAL \A:Q1[13]~q\ : std_logic;
SIGNAL \A:Q1[13]~2\ : std_logic;
SIGNAL \A:Q1[14]~1_combout\ : std_logic;
SIGNAL \A:Q1[14]~q\ : std_logic;
SIGNAL \A:Q1[14]~2\ : std_logic;
SIGNAL \A:Q1[15]~1_combout\ : std_logic;
SIGNAL \A:Q1[15]~q\ : std_logic;
SIGNAL \A:Q1[15]~2\ : std_logic;
SIGNAL \A:Q1[16]~1_combout\ : std_logic;
SIGNAL \A:Q1[16]~q\ : std_logic;
SIGNAL \A:Q1[16]~2\ : std_logic;
SIGNAL \A:Q1[17]~1_combout\ : std_logic;
SIGNAL \A:Q1[17]~q\ : std_logic;
SIGNAL \A:Q1[17]~2\ : std_logic;
SIGNAL \A:Q1[18]~1_combout\ : std_logic;
SIGNAL \A:Q1[18]~q\ : std_logic;
SIGNAL \A:Q1[18]~2\ : std_logic;
SIGNAL \A:Q1[19]~1_combout\ : std_logic;
SIGNAL \A:Q1[19]~q\ : std_logic;
SIGNAL \A:Q1[19]~2\ : std_logic;
SIGNAL \A:Q1[20]~1_combout\ : std_logic;
SIGNAL \A:Q1[20]~q\ : std_logic;
SIGNAL \A:Q1[20]~2\ : std_logic;
SIGNAL \A:Q1[21]~1_combout\ : std_logic;
SIGNAL \A:Q1[21]~q\ : std_logic;
SIGNAL \A:Q1[21]~2\ : std_logic;
SIGNAL \A:Q1[22]~1_combout\ : std_logic;
SIGNAL \A:Q1[22]~q\ : std_logic;
SIGNAL \A:Q1[22]~2\ : std_logic;
SIGNAL \A:Q1[23]~1_combout\ : std_logic;
SIGNAL \A:Q1[23]~q\ : std_logic;
SIGNAL \A:Q1[23]~2\ : std_logic;
SIGNAL \A:Q1[24]~1_combout\ : std_logic;
SIGNAL \A:Q1[24]~q\ : std_logic;
SIGNAL \A:Q1[24]~2\ : std_logic;
SIGNAL \A:Q1[25]~1_combout\ : std_logic;
SIGNAL \A:Q1[25]~q\ : std_logic;
SIGNAL \A:Q1[25]~2\ : std_logic;
SIGNAL \A:Q1[26]~1_combout\ : std_logic;
SIGNAL \A:Q1[26]~q\ : std_logic;
SIGNAL \A:Q1[26]~2\ : std_logic;
SIGNAL \A:Q1[27]~1_combout\ : std_logic;
SIGNAL \A:Q1[27]~q\ : std_logic;
SIGNAL \A:Q1[27]~2\ : std_logic;
SIGNAL \A:Q1[28]~1_combout\ : std_logic;
SIGNAL \A:Q1[28]~q\ : std_logic;
SIGNAL \A:Q1[28]~2\ : std_logic;
SIGNAL \A:Q1[29]~1_combout\ : std_logic;
SIGNAL \A:Q1[29]~q\ : std_logic;
SIGNAL \A:Q1[29]~2\ : std_logic;
SIGNAL \A:Q1[30]~1_combout\ : std_logic;
SIGNAL \A:Q1[30]~q\ : std_logic;
SIGNAL \A:Q1[30]~2\ : std_logic;
SIGNAL \A:Q1[31]~1_combout\ : std_logic;
SIGNAL \A:Q1[31]~q\ : std_logic;
SIGNAL \CLKBASE~input_o\ : std_logic;
SIGNAL \CLKBASE~inputclkctrl_outclk\ : std_logic;
SIGNAL \B:Q1BASE[0]~0_combout\ : std_logic;
SIGNAL \B:Q1BASE[0]~q\ : std_logic;
SIGNAL \B:Q1BASE[1]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[1]~q\ : std_logic;
SIGNAL \B:Q1BASE[1]~2\ : std_logic;
SIGNAL \B:Q1BASE[2]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[2]~q\ : std_logic;
SIGNAL \B:Q1BASE[2]~2\ : std_logic;
SIGNAL \B:Q1BASE[3]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[3]~q\ : std_logic;
SIGNAL \B:Q1BASE[3]~2\ : std_logic;
SIGNAL \B:Q1BASE[4]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[4]~q\ : std_logic;
SIGNAL \B:Q1BASE[4]~2\ : std_logic;
SIGNAL \B:Q1BASE[5]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[5]~q\ : std_logic;
SIGNAL \B:Q1BASE[5]~2\ : std_logic;
SIGNAL \B:Q1BASE[6]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[6]~q\ : std_logic;
SIGNAL \B:Q1BASE[6]~2\ : std_logic;
SIGNAL \B:Q1BASE[7]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[7]~q\ : std_logic;
SIGNAL \B:Q1BASE[7]~2\ : std_logic;
SIGNAL \B:Q1BASE[8]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[8]~q\ : std_logic;
SIGNAL \B:Q1BASE[8]~2\ : std_logic;
SIGNAL \B:Q1BASE[9]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[9]~q\ : std_logic;
SIGNAL \B:Q1BASE[9]~2\ : std_logic;
SIGNAL \B:Q1BASE[10]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[10]~q\ : std_logic;
SIGNAL \B:Q1BASE[10]~2\ : std_logic;
SIGNAL \B:Q1BASE[11]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[11]~q\ : std_logic;
SIGNAL \B:Q1BASE[11]~2\ : std_logic;
SIGNAL \B:Q1BASE[12]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[12]~q\ : std_logic;
SIGNAL \B:Q1BASE[12]~2\ : std_logic;
SIGNAL \B:Q1BASE[13]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[13]~q\ : std_logic;
SIGNAL \B:Q1BASE[13]~2\ : std_logic;
SIGNAL \B:Q1BASE[14]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[14]~q\ : std_logic;
SIGNAL \B:Q1BASE[14]~2\ : std_logic;
SIGNAL \B:Q1BASE[15]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[15]~q\ : std_logic;
SIGNAL \B:Q1BASE[15]~2\ : std_logic;
SIGNAL \B:Q1BASE[16]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[16]~q\ : std_logic;
SIGNAL \B:Q1BASE[16]~2\ : std_logic;
SIGNAL \B:Q1BASE[17]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[17]~q\ : std_logic;
SIGNAL \B:Q1BASE[17]~2\ : std_logic;
SIGNAL \B:Q1BASE[18]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[18]~q\ : std_logic;
SIGNAL \B:Q1BASE[18]~2\ : std_logic;
SIGNAL \B:Q1BASE[19]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[19]~q\ : std_logic;
SIGNAL \B:Q1BASE[19]~2\ : std_logic;
SIGNAL \B:Q1BASE[20]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[20]~q\ : std_logic;
SIGNAL \B:Q1BASE[20]~2\ : std_logic;
SIGNAL \B:Q1BASE[21]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[21]~q\ : std_logic;
SIGNAL \B:Q1BASE[21]~2\ : std_logic;
SIGNAL \B:Q1BASE[22]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[22]~q\ : std_logic;
SIGNAL \B:Q1BASE[22]~2\ : std_logic;
SIGNAL \B:Q1BASE[23]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[23]~q\ : std_logic;
SIGNAL \B:Q1BASE[23]~2\ : std_logic;
SIGNAL \B:Q1BASE[24]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[24]~q\ : std_logic;
SIGNAL \B:Q1BASE[24]~2\ : std_logic;
SIGNAL \B:Q1BASE[25]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[25]~q\ : std_logic;
SIGNAL \B:Q1BASE[25]~2\ : std_logic;
SIGNAL \B:Q1BASE[26]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[26]~q\ : std_logic;
SIGNAL \B:Q1BASE[26]~2\ : std_logic;
SIGNAL \B:Q1BASE[27]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[27]~q\ : std_logic;
SIGNAL \B:Q1BASE[27]~2\ : std_logic;
SIGNAL \B:Q1BASE[28]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[28]~q\ : std_logic;
SIGNAL \B:Q1BASE[28]~2\ : std_logic;
SIGNAL \B:Q1BASE[29]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[29]~q\ : std_logic;
SIGNAL \B:Q1BASE[29]~2\ : std_logic;
SIGNAL \B:Q1BASE[30]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[30]~q\ : std_logic;
SIGNAL \B:Q1BASE[30]~2\ : std_logic;
SIGNAL \B:Q1BASE[31]~1_combout\ : std_logic;
SIGNAL \B:Q1BASE[31]~q\ : std_logic;

BEGIN

ww_CLR <= CLR;
ww_CLK <= CLK;
ww_CLKBASE <= CLKBASE;
ww_CLKEN <= CLKEN;
ww_CLKBASEEN <= CLKBASEEN;
Q <= ww_Q;
QBASE <= ww_QBASE;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\CLR~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \CLR~input_o\);

\CLK~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \CLK~input_o\);

\CLKBASE~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \CLKBASE~input_o\);

-- Location: IOOBUF_X18_Y0_N16
\Q[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[0]~q\,
	devoe => ww_devoe,
	o => \Q[0]~output_o\);

-- Location: IOOBUF_X34_Y4_N23
\Q[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[1]~q\,
	devoe => ww_devoe,
	o => \Q[1]~output_o\);

-- Location: IOOBUF_X30_Y0_N23
\Q[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[2]~q\,
	devoe => ww_devoe,
	o => \Q[2]~output_o\);

-- Location: IOOBUF_X23_Y0_N9
\Q[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[3]~q\,
	devoe => ww_devoe,
	o => \Q[3]~output_o\);

-- Location: IOOBUF_X28_Y0_N23
\Q[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[4]~q\,
	devoe => ww_devoe,
	o => \Q[4]~output_o\);

-- Location: IOOBUF_X34_Y17_N2
\Q[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[5]~q\,
	devoe => ww_devoe,
	o => \Q[5]~output_o\);

-- Location: IOOBUF_X34_Y9_N16
\Q[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[6]~q\,
	devoe => ww_devoe,
	o => \Q[6]~output_o\);

-- Location: IOOBUF_X34_Y17_N23
\Q[7]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[7]~q\,
	devoe => ww_devoe,
	o => \Q[7]~output_o\);

-- Location: IOOBUF_X34_Y7_N9
\Q[8]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[8]~q\,
	devoe => ww_devoe,
	o => \Q[8]~output_o\);

-- Location: IOOBUF_X34_Y4_N16
\Q[9]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[9]~q\,
	devoe => ww_devoe,
	o => \Q[9]~output_o\);

-- Location: IOOBUF_X34_Y9_N2
\Q[10]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[10]~q\,
	devoe => ww_devoe,
	o => \Q[10]~output_o\);

-- Location: IOOBUF_X34_Y17_N16
\Q[11]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[11]~q\,
	devoe => ww_devoe,
	o => \Q[11]~output_o\);

-- Location: IOOBUF_X34_Y9_N9
\Q[12]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[12]~q\,
	devoe => ww_devoe,
	o => \Q[12]~output_o\);

-- Location: IOOBUF_X34_Y9_N23
\Q[13]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[13]~q\,
	devoe => ww_devoe,
	o => \Q[13]~output_o\);

-- Location: IOOBUF_X34_Y18_N2
\Q[14]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[14]~q\,
	devoe => ww_devoe,
	o => \Q[14]~output_o\);

-- Location: IOOBUF_X34_Y10_N9
\Q[15]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[15]~q\,
	devoe => ww_devoe,
	o => \Q[15]~output_o\);

-- Location: IOOBUF_X34_Y2_N16
\Q[16]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[16]~q\,
	devoe => ww_devoe,
	o => \Q[16]~output_o\);

-- Location: IOOBUF_X16_Y0_N23
\Q[17]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[17]~q\,
	devoe => ww_devoe,
	o => \Q[17]~output_o\);

-- Location: IOOBUF_X23_Y0_N16
\Q[18]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[18]~q\,
	devoe => ww_devoe,
	o => \Q[18]~output_o\);

-- Location: IOOBUF_X30_Y0_N9
\Q[19]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[19]~q\,
	devoe => ww_devoe,
	o => \Q[19]~output_o\);

-- Location: IOOBUF_X16_Y0_N9
\Q[20]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[20]~q\,
	devoe => ww_devoe,
	o => \Q[20]~output_o\);

-- Location: IOOBUF_X28_Y0_N2
\Q[21]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[21]~q\,
	devoe => ww_devoe,
	o => \Q[21]~output_o\);

-- Location: IOOBUF_X16_Y0_N2
\Q[22]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[22]~q\,
	devoe => ww_devoe,
	o => \Q[22]~output_o\);

-- Location: IOOBUF_X34_Y3_N23
\Q[23]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[23]~q\,
	devoe => ww_devoe,
	o => \Q[23]~output_o\);

-- Location: IOOBUF_X25_Y0_N2
\Q[24]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[24]~q\,
	devoe => ww_devoe,
	o => \Q[24]~output_o\);

-- Location: IOOBUF_X30_Y0_N2
\Q[25]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[25]~q\,
	devoe => ww_devoe,
	o => \Q[25]~output_o\);

-- Location: IOOBUF_X18_Y0_N23
\Q[26]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[26]~q\,
	devoe => ww_devoe,
	o => \Q[26]~output_o\);

-- Location: IOOBUF_X34_Y2_N23
\Q[27]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[27]~q\,
	devoe => ww_devoe,
	o => \Q[27]~output_o\);

-- Location: IOOBUF_X32_Y0_N23
\Q[28]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[28]~q\,
	devoe => ww_devoe,
	o => \Q[28]~output_o\);

-- Location: IOOBUF_X21_Y0_N9
\Q[29]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[29]~q\,
	devoe => ww_devoe,
	o => \Q[29]~output_o\);

-- Location: IOOBUF_X32_Y0_N9
\Q[30]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[30]~q\,
	devoe => ww_devoe,
	o => \Q[30]~output_o\);

-- Location: IOOBUF_X32_Y0_N16
\Q[31]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \A:Q1[31]~q\,
	devoe => ww_devoe,
	o => \Q[31]~output_o\);

-- Location: IOOBUF_X7_Y24_N2
\QBASE[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[0]~q\,
	devoe => ww_devoe,
	o => \QBASE[0]~output_o\);

-- Location: IOOBUF_X13_Y24_N23
\QBASE[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[1]~q\,
	devoe => ww_devoe,
	o => \QBASE[1]~output_o\);

-- Location: IOOBUF_X0_Y9_N9
\QBASE[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[2]~q\,
	devoe => ww_devoe,
	o => \QBASE[2]~output_o\);

-- Location: IOOBUF_X7_Y24_N9
\QBASE[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[3]~q\,
	devoe => ww_devoe,
	o => \QBASE[3]~output_o\);

-- Location: IOOBUF_X16_Y24_N16
\QBASE[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[4]~q\,
	devoe => ww_devoe,
	o => \QBASE[4]~output_o\);

-- Location: IOOBUF_X16_Y24_N23
\QBASE[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[5]~q\,
	devoe => ww_devoe,
	o => \QBASE[5]~output_o\);

-- Location: IOOBUF_X0_Y23_N16
\QBASE[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[6]~q\,
	devoe => ww_devoe,
	o => \QBASE[6]~output_o\);

-- Location: IOOBUF_X1_Y24_N2
\QBASE[7]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[7]~q\,
	devoe => ww_devoe,
	o => \QBASE[7]~output_o\);

-- Location: IOOBUF_X0_Y23_N9
\QBASE[8]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[8]~q\,
	devoe => ww_devoe,
	o => \QBASE[8]~output_o\);

-- Location: IOOBUF_X28_Y24_N23
\QBASE[9]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[9]~q\,
	devoe => ww_devoe,
	o => \QBASE[9]~output_o\);

-- Location: IOOBUF_X3_Y24_N23
\QBASE[10]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[10]~q\,
	devoe => ww_devoe,
	o => \QBASE[10]~output_o\);

-- Location: IOOBUF_X0_Y23_N2
\QBASE[11]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[11]~q\,
	devoe => ww_devoe,
	o => \QBASE[11]~output_o\);

-- Location: IOOBUF_X5_Y24_N9
\QBASE[12]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[12]~q\,
	devoe => ww_devoe,
	o => \QBASE[12]~output_o\);

-- Location: IOOBUF_X11_Y24_N16
\QBASE[13]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[13]~q\,
	devoe => ww_devoe,
	o => \QBASE[13]~output_o\);

-- Location: IOOBUF_X9_Y24_N9
\QBASE[14]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[14]~q\,
	devoe => ww_devoe,
	o => \QBASE[14]~output_o\);

-- Location: IOOBUF_X13_Y24_N16
\QBASE[15]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[15]~q\,
	devoe => ww_devoe,
	o => \QBASE[15]~output_o\);

-- Location: IOOBUF_X0_Y18_N16
\QBASE[16]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[16]~q\,
	devoe => ww_devoe,
	o => \QBASE[16]~output_o\);

-- Location: IOOBUF_X0_Y6_N23
\QBASE[17]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[17]~q\,
	devoe => ww_devoe,
	o => \QBASE[17]~output_o\);

-- Location: IOOBUF_X1_Y24_N9
\QBASE[18]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[18]~q\,
	devoe => ww_devoe,
	o => \QBASE[18]~output_o\);

-- Location: IOOBUF_X23_Y24_N9
\QBASE[19]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[19]~q\,
	devoe => ww_devoe,
	o => \QBASE[19]~output_o\);

-- Location: IOOBUF_X0_Y6_N16
\QBASE[20]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[20]~q\,
	devoe => ww_devoe,
	o => \QBASE[20]~output_o\);

-- Location: IOOBUF_X18_Y24_N16
\QBASE[21]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[21]~q\,
	devoe => ww_devoe,
	o => \QBASE[21]~output_o\);

-- Location: IOOBUF_X7_Y0_N2
\QBASE[22]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[22]~q\,
	devoe => ww_devoe,
	o => \QBASE[22]~output_o\);

-- Location: IOOBUF_X0_Y7_N2
\QBASE[23]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[23]~q\,
	devoe => ww_devoe,
	o => \QBASE[23]~output_o\);

-- Location: IOOBUF_X23_Y24_N16
\QBASE[24]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[24]~q\,
	devoe => ww_devoe,
	o => \QBASE[24]~output_o\);

-- Location: IOOBUF_X23_Y24_N2
\QBASE[25]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[25]~q\,
	devoe => ww_devoe,
	o => \QBASE[25]~output_o\);

-- Location: IOOBUF_X0_Y8_N16
\QBASE[26]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[26]~q\,
	devoe => ww_devoe,
	o => \QBASE[26]~output_o\);

-- Location: IOOBUF_X16_Y24_N9
\QBASE[27]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[27]~q\,
	devoe => ww_devoe,
	o => \QBASE[27]~output_o\);

-- Location: IOOBUF_X0_Y21_N9
\QBASE[28]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[28]~q\,
	devoe => ww_devoe,
	o => \QBASE[28]~output_o\);

-- Location: IOOBUF_X0_Y18_N23
\QBASE[29]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[29]~q\,
	devoe => ww_devoe,
	o => \QBASE[29]~output_o\);

-- Location: IOOBUF_X16_Y24_N2
\QBASE[30]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[30]~q\,
	devoe => ww_devoe,
	o => \QBASE[30]~output_o\);

-- Location: IOOBUF_X18_Y24_N23
\QBASE[31]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \B:Q1BASE[31]~q\,
	devoe => ww_devoe,
	o => \QBASE[31]~output_o\);

-- Location: IOIBUF_X0_Y11_N15
\CLK~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLK,
	o => \CLK~input_o\);

-- Location: CLKCTRL_G4
\CLK~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \CLK~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLK~inputclkctrl_outclk\);

-- Location: LCCOMB_X30_Y4_N0
\A:Q1[0]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[0]~1_combout\ = !\A:Q1[0]~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \A:Q1[0]~q\,
	combout => \A:Q1[0]~1_combout\);

-- Location: IOIBUF_X0_Y11_N22
\CLR~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLR,
	o => \CLR~input_o\);

-- Location: CLKCTRL_G3
\CLR~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \CLR~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLR~inputclkctrl_outclk\);

-- Location: IOIBUF_X30_Y24_N22
\CLKEN~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLKEN,
	o => \CLKEN~input_o\);

-- Location: IOIBUF_X34_Y20_N8
\CLKBASEEN~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLKBASEEN,
	o => \CLKBASEEN~input_o\);

-- Location: LCCOMB_X30_Y20_N8
\A:Q1[0]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[0]~0_combout\ = (\CLKEN~input_o\ & \CLKBASEEN~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \CLKEN~input_o\,
	datad => \CLKBASEEN~input_o\,
	combout => \A:Q1[0]~0_combout\);

-- Location: FF_X30_Y4_N1
\A:Q1[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[0]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[0]~q\);

-- Location: LCCOMB_X30_Y4_N2
\A:Q1[1]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[1]~1_combout\ = (\A:Q1[0]~q\ & (\A:Q1[1]~q\ $ (VCC))) # (!\A:Q1[0]~q\ & (\A:Q1[1]~q\ & VCC))
-- \A:Q1[1]~2\ = CARRY((\A:Q1[0]~q\ & \A:Q1[1]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110011010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[0]~q\,
	datab => \A:Q1[1]~q\,
	datad => VCC,
	combout => \A:Q1[1]~1_combout\,
	cout => \A:Q1[1]~2\);

-- Location: FF_X30_Y4_N3
\A:Q1[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[1]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[1]~q\);

-- Location: LCCOMB_X30_Y4_N4
\A:Q1[2]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[2]~1_combout\ = (\A:Q1[2]~q\ & (!\A:Q1[1]~2\)) # (!\A:Q1[2]~q\ & ((\A:Q1[1]~2\) # (GND)))
-- \A:Q1[2]~2\ = CARRY((!\A:Q1[1]~2\) # (!\A:Q1[2]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[2]~q\,
	datad => VCC,
	cin => \A:Q1[1]~2\,
	combout => \A:Q1[2]~1_combout\,
	cout => \A:Q1[2]~2\);

-- Location: FF_X30_Y4_N5
\A:Q1[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[2]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[2]~q\);

-- Location: LCCOMB_X30_Y4_N6
\A:Q1[3]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[3]~1_combout\ = (\A:Q1[3]~q\ & (\A:Q1[2]~2\ $ (GND))) # (!\A:Q1[3]~q\ & (!\A:Q1[2]~2\ & VCC))
-- \A:Q1[3]~2\ = CARRY((\A:Q1[3]~q\ & !\A:Q1[2]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[3]~q\,
	datad => VCC,
	cin => \A:Q1[2]~2\,
	combout => \A:Q1[3]~1_combout\,
	cout => \A:Q1[3]~2\);

-- Location: FF_X30_Y4_N7
\A:Q1[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[3]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[3]~q\);

-- Location: LCCOMB_X30_Y4_N8
\A:Q1[4]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[4]~1_combout\ = (\A:Q1[4]~q\ & (!\A:Q1[3]~2\)) # (!\A:Q1[4]~q\ & ((\A:Q1[3]~2\) # (GND)))
-- \A:Q1[4]~2\ = CARRY((!\A:Q1[3]~2\) # (!\A:Q1[4]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[4]~q\,
	datad => VCC,
	cin => \A:Q1[3]~2\,
	combout => \A:Q1[4]~1_combout\,
	cout => \A:Q1[4]~2\);

-- Location: FF_X30_Y4_N9
\A:Q1[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[4]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[4]~q\);

-- Location: LCCOMB_X30_Y4_N10
\A:Q1[5]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[5]~1_combout\ = (\A:Q1[5]~q\ & (\A:Q1[4]~2\ $ (GND))) # (!\A:Q1[5]~q\ & (!\A:Q1[4]~2\ & VCC))
-- \A:Q1[5]~2\ = CARRY((\A:Q1[5]~q\ & !\A:Q1[4]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[5]~q\,
	datad => VCC,
	cin => \A:Q1[4]~2\,
	combout => \A:Q1[5]~1_combout\,
	cout => \A:Q1[5]~2\);

-- Location: FF_X30_Y4_N11
\A:Q1[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[5]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[5]~q\);

-- Location: LCCOMB_X30_Y4_N12
\A:Q1[6]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[6]~1_combout\ = (\A:Q1[6]~q\ & (!\A:Q1[5]~2\)) # (!\A:Q1[6]~q\ & ((\A:Q1[5]~2\) # (GND)))
-- \A:Q1[6]~2\ = CARRY((!\A:Q1[5]~2\) # (!\A:Q1[6]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[6]~q\,
	datad => VCC,
	cin => \A:Q1[5]~2\,
	combout => \A:Q1[6]~1_combout\,
	cout => \A:Q1[6]~2\);

-- Location: FF_X30_Y4_N13
\A:Q1[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[6]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[6]~q\);

-- Location: LCCOMB_X30_Y4_N14
\A:Q1[7]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[7]~1_combout\ = (\A:Q1[7]~q\ & (\A:Q1[6]~2\ $ (GND))) # (!\A:Q1[7]~q\ & (!\A:Q1[6]~2\ & VCC))
-- \A:Q1[7]~2\ = CARRY((\A:Q1[7]~q\ & !\A:Q1[6]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[7]~q\,
	datad => VCC,
	cin => \A:Q1[6]~2\,
	combout => \A:Q1[7]~1_combout\,
	cout => \A:Q1[7]~2\);

-- Location: FF_X30_Y4_N15
\A:Q1[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[7]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[7]~q\);

-- Location: LCCOMB_X30_Y4_N16
\A:Q1[8]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[8]~1_combout\ = (\A:Q1[8]~q\ & (!\A:Q1[7]~2\)) # (!\A:Q1[8]~q\ & ((\A:Q1[7]~2\) # (GND)))
-- \A:Q1[8]~2\ = CARRY((!\A:Q1[7]~2\) # (!\A:Q1[8]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[8]~q\,
	datad => VCC,
	cin => \A:Q1[7]~2\,
	combout => \A:Q1[8]~1_combout\,
	cout => \A:Q1[8]~2\);

-- Location: FF_X30_Y4_N17
\A:Q1[8]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[8]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[8]~q\);

-- Location: LCCOMB_X30_Y4_N18
\A:Q1[9]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[9]~1_combout\ = (\A:Q1[9]~q\ & (\A:Q1[8]~2\ $ (GND))) # (!\A:Q1[9]~q\ & (!\A:Q1[8]~2\ & VCC))
-- \A:Q1[9]~2\ = CARRY((\A:Q1[9]~q\ & !\A:Q1[8]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[9]~q\,
	datad => VCC,
	cin => \A:Q1[8]~2\,
	combout => \A:Q1[9]~1_combout\,
	cout => \A:Q1[9]~2\);

-- Location: FF_X30_Y4_N19
\A:Q1[9]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[9]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[9]~q\);

-- Location: LCCOMB_X30_Y4_N20
\A:Q1[10]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[10]~1_combout\ = (\A:Q1[10]~q\ & (!\A:Q1[9]~2\)) # (!\A:Q1[10]~q\ & ((\A:Q1[9]~2\) # (GND)))
-- \A:Q1[10]~2\ = CARRY((!\A:Q1[9]~2\) # (!\A:Q1[10]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[10]~q\,
	datad => VCC,
	cin => \A:Q1[9]~2\,
	combout => \A:Q1[10]~1_combout\,
	cout => \A:Q1[10]~2\);

-- Location: FF_X30_Y4_N21
\A:Q1[10]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[10]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[10]~q\);

-- Location: LCCOMB_X30_Y4_N22
\A:Q1[11]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[11]~1_combout\ = (\A:Q1[11]~q\ & (\A:Q1[10]~2\ $ (GND))) # (!\A:Q1[11]~q\ & (!\A:Q1[10]~2\ & VCC))
-- \A:Q1[11]~2\ = CARRY((\A:Q1[11]~q\ & !\A:Q1[10]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[11]~q\,
	datad => VCC,
	cin => \A:Q1[10]~2\,
	combout => \A:Q1[11]~1_combout\,
	cout => \A:Q1[11]~2\);

-- Location: FF_X30_Y4_N23
\A:Q1[11]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[11]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[11]~q\);

-- Location: LCCOMB_X30_Y4_N24
\A:Q1[12]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[12]~1_combout\ = (\A:Q1[12]~q\ & (!\A:Q1[11]~2\)) # (!\A:Q1[12]~q\ & ((\A:Q1[11]~2\) # (GND)))
-- \A:Q1[12]~2\ = CARRY((!\A:Q1[11]~2\) # (!\A:Q1[12]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[12]~q\,
	datad => VCC,
	cin => \A:Q1[11]~2\,
	combout => \A:Q1[12]~1_combout\,
	cout => \A:Q1[12]~2\);

-- Location: FF_X30_Y4_N25
\A:Q1[12]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[12]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[12]~q\);

-- Location: LCCOMB_X30_Y4_N26
\A:Q1[13]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[13]~1_combout\ = (\A:Q1[13]~q\ & (\A:Q1[12]~2\ $ (GND))) # (!\A:Q1[13]~q\ & (!\A:Q1[12]~2\ & VCC))
-- \A:Q1[13]~2\ = CARRY((\A:Q1[13]~q\ & !\A:Q1[12]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[13]~q\,
	datad => VCC,
	cin => \A:Q1[12]~2\,
	combout => \A:Q1[13]~1_combout\,
	cout => \A:Q1[13]~2\);

-- Location: FF_X30_Y4_N27
\A:Q1[13]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[13]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[13]~q\);

-- Location: LCCOMB_X30_Y4_N28
\A:Q1[14]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[14]~1_combout\ = (\A:Q1[14]~q\ & (!\A:Q1[13]~2\)) # (!\A:Q1[14]~q\ & ((\A:Q1[13]~2\) # (GND)))
-- \A:Q1[14]~2\ = CARRY((!\A:Q1[13]~2\) # (!\A:Q1[14]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[14]~q\,
	datad => VCC,
	cin => \A:Q1[13]~2\,
	combout => \A:Q1[14]~1_combout\,
	cout => \A:Q1[14]~2\);

-- Location: FF_X30_Y4_N29
\A:Q1[14]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[14]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[14]~q\);

-- Location: LCCOMB_X30_Y4_N30
\A:Q1[15]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[15]~1_combout\ = (\A:Q1[15]~q\ & (\A:Q1[14]~2\ $ (GND))) # (!\A:Q1[15]~q\ & (!\A:Q1[14]~2\ & VCC))
-- \A:Q1[15]~2\ = CARRY((\A:Q1[15]~q\ & !\A:Q1[14]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[15]~q\,
	datad => VCC,
	cin => \A:Q1[14]~2\,
	combout => \A:Q1[15]~1_combout\,
	cout => \A:Q1[15]~2\);

-- Location: FF_X30_Y4_N31
\A:Q1[15]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[15]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[15]~q\);

-- Location: LCCOMB_X30_Y3_N0
\A:Q1[16]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[16]~1_combout\ = (\A:Q1[16]~q\ & (!\A:Q1[15]~2\)) # (!\A:Q1[16]~q\ & ((\A:Q1[15]~2\) # (GND)))
-- \A:Q1[16]~2\ = CARRY((!\A:Q1[15]~2\) # (!\A:Q1[16]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[16]~q\,
	datad => VCC,
	cin => \A:Q1[15]~2\,
	combout => \A:Q1[16]~1_combout\,
	cout => \A:Q1[16]~2\);

-- Location: FF_X30_Y3_N1
\A:Q1[16]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[16]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[16]~q\);

-- Location: LCCOMB_X30_Y3_N2
\A:Q1[17]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[17]~1_combout\ = (\A:Q1[17]~q\ & (\A:Q1[16]~2\ $ (GND))) # (!\A:Q1[17]~q\ & (!\A:Q1[16]~2\ & VCC))
-- \A:Q1[17]~2\ = CARRY((\A:Q1[17]~q\ & !\A:Q1[16]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[17]~q\,
	datad => VCC,
	cin => \A:Q1[16]~2\,
	combout => \A:Q1[17]~1_combout\,
	cout => \A:Q1[17]~2\);

-- Location: FF_X30_Y3_N3
\A:Q1[17]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[17]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[17]~q\);

-- Location: LCCOMB_X30_Y3_N4
\A:Q1[18]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[18]~1_combout\ = (\A:Q1[18]~q\ & (!\A:Q1[17]~2\)) # (!\A:Q1[18]~q\ & ((\A:Q1[17]~2\) # (GND)))
-- \A:Q1[18]~2\ = CARRY((!\A:Q1[17]~2\) # (!\A:Q1[18]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[18]~q\,
	datad => VCC,
	cin => \A:Q1[17]~2\,
	combout => \A:Q1[18]~1_combout\,
	cout => \A:Q1[18]~2\);

-- Location: FF_X30_Y3_N5
\A:Q1[18]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[18]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[18]~q\);

-- Location: LCCOMB_X30_Y3_N6
\A:Q1[19]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[19]~1_combout\ = (\A:Q1[19]~q\ & (\A:Q1[18]~2\ $ (GND))) # (!\A:Q1[19]~q\ & (!\A:Q1[18]~2\ & VCC))
-- \A:Q1[19]~2\ = CARRY((\A:Q1[19]~q\ & !\A:Q1[18]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[19]~q\,
	datad => VCC,
	cin => \A:Q1[18]~2\,
	combout => \A:Q1[19]~1_combout\,
	cout => \A:Q1[19]~2\);

-- Location: FF_X30_Y3_N7
\A:Q1[19]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[19]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[19]~q\);

-- Location: LCCOMB_X30_Y3_N8
\A:Q1[20]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[20]~1_combout\ = (\A:Q1[20]~q\ & (!\A:Q1[19]~2\)) # (!\A:Q1[20]~q\ & ((\A:Q1[19]~2\) # (GND)))
-- \A:Q1[20]~2\ = CARRY((!\A:Q1[19]~2\) # (!\A:Q1[20]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[20]~q\,
	datad => VCC,
	cin => \A:Q1[19]~2\,
	combout => \A:Q1[20]~1_combout\,
	cout => \A:Q1[20]~2\);

-- Location: FF_X30_Y3_N9
\A:Q1[20]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[20]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[20]~q\);

-- Location: LCCOMB_X30_Y3_N10
\A:Q1[21]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[21]~1_combout\ = (\A:Q1[21]~q\ & (\A:Q1[20]~2\ $ (GND))) # (!\A:Q1[21]~q\ & (!\A:Q1[20]~2\ & VCC))
-- \A:Q1[21]~2\ = CARRY((\A:Q1[21]~q\ & !\A:Q1[20]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[21]~q\,
	datad => VCC,
	cin => \A:Q1[20]~2\,
	combout => \A:Q1[21]~1_combout\,
	cout => \A:Q1[21]~2\);

-- Location: FF_X30_Y3_N11
\A:Q1[21]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[21]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[21]~q\);

-- Location: LCCOMB_X30_Y3_N12
\A:Q1[22]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[22]~1_combout\ = (\A:Q1[22]~q\ & (!\A:Q1[21]~2\)) # (!\A:Q1[22]~q\ & ((\A:Q1[21]~2\) # (GND)))
-- \A:Q1[22]~2\ = CARRY((!\A:Q1[21]~2\) # (!\A:Q1[22]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[22]~q\,
	datad => VCC,
	cin => \A:Q1[21]~2\,
	combout => \A:Q1[22]~1_combout\,
	cout => \A:Q1[22]~2\);

-- Location: FF_X30_Y3_N13
\A:Q1[22]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[22]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[22]~q\);

-- Location: LCCOMB_X30_Y3_N14
\A:Q1[23]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[23]~1_combout\ = (\A:Q1[23]~q\ & (\A:Q1[22]~2\ $ (GND))) # (!\A:Q1[23]~q\ & (!\A:Q1[22]~2\ & VCC))
-- \A:Q1[23]~2\ = CARRY((\A:Q1[23]~q\ & !\A:Q1[22]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[23]~q\,
	datad => VCC,
	cin => \A:Q1[22]~2\,
	combout => \A:Q1[23]~1_combout\,
	cout => \A:Q1[23]~2\);

-- Location: FF_X30_Y3_N15
\A:Q1[23]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[23]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[23]~q\);

-- Location: LCCOMB_X30_Y3_N16
\A:Q1[24]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[24]~1_combout\ = (\A:Q1[24]~q\ & (!\A:Q1[23]~2\)) # (!\A:Q1[24]~q\ & ((\A:Q1[23]~2\) # (GND)))
-- \A:Q1[24]~2\ = CARRY((!\A:Q1[23]~2\) # (!\A:Q1[24]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[24]~q\,
	datad => VCC,
	cin => \A:Q1[23]~2\,
	combout => \A:Q1[24]~1_combout\,
	cout => \A:Q1[24]~2\);

-- Location: FF_X30_Y3_N17
\A:Q1[24]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[24]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[24]~q\);

-- Location: LCCOMB_X30_Y3_N18
\A:Q1[25]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[25]~1_combout\ = (\A:Q1[25]~q\ & (\A:Q1[24]~2\ $ (GND))) # (!\A:Q1[25]~q\ & (!\A:Q1[24]~2\ & VCC))
-- \A:Q1[25]~2\ = CARRY((\A:Q1[25]~q\ & !\A:Q1[24]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[25]~q\,
	datad => VCC,
	cin => \A:Q1[24]~2\,
	combout => \A:Q1[25]~1_combout\,
	cout => \A:Q1[25]~2\);

-- Location: FF_X30_Y3_N19
\A:Q1[25]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[25]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[25]~q\);

-- Location: LCCOMB_X30_Y3_N20
\A:Q1[26]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[26]~1_combout\ = (\A:Q1[26]~q\ & (!\A:Q1[25]~2\)) # (!\A:Q1[26]~q\ & ((\A:Q1[25]~2\) # (GND)))
-- \A:Q1[26]~2\ = CARRY((!\A:Q1[25]~2\) # (!\A:Q1[26]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[26]~q\,
	datad => VCC,
	cin => \A:Q1[25]~2\,
	combout => \A:Q1[26]~1_combout\,
	cout => \A:Q1[26]~2\);

-- Location: FF_X30_Y3_N21
\A:Q1[26]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[26]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[26]~q\);

-- Location: LCCOMB_X30_Y3_N22
\A:Q1[27]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[27]~1_combout\ = (\A:Q1[27]~q\ & (\A:Q1[26]~2\ $ (GND))) # (!\A:Q1[27]~q\ & (!\A:Q1[26]~2\ & VCC))
-- \A:Q1[27]~2\ = CARRY((\A:Q1[27]~q\ & !\A:Q1[26]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[27]~q\,
	datad => VCC,
	cin => \A:Q1[26]~2\,
	combout => \A:Q1[27]~1_combout\,
	cout => \A:Q1[27]~2\);

-- Location: FF_X30_Y3_N23
\A:Q1[27]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[27]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[27]~q\);

-- Location: LCCOMB_X30_Y3_N24
\A:Q1[28]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[28]~1_combout\ = (\A:Q1[28]~q\ & (!\A:Q1[27]~2\)) # (!\A:Q1[28]~q\ & ((\A:Q1[27]~2\) # (GND)))
-- \A:Q1[28]~2\ = CARRY((!\A:Q1[27]~2\) # (!\A:Q1[28]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[28]~q\,
	datad => VCC,
	cin => \A:Q1[27]~2\,
	combout => \A:Q1[28]~1_combout\,
	cout => \A:Q1[28]~2\);

-- Location: FF_X30_Y3_N25
\A:Q1[28]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[28]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[28]~q\);

-- Location: LCCOMB_X30_Y3_N26
\A:Q1[29]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[29]~1_combout\ = (\A:Q1[29]~q\ & (\A:Q1[28]~2\ $ (GND))) # (!\A:Q1[29]~q\ & (!\A:Q1[28]~2\ & VCC))
-- \A:Q1[29]~2\ = CARRY((\A:Q1[29]~q\ & !\A:Q1[28]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[29]~q\,
	datad => VCC,
	cin => \A:Q1[28]~2\,
	combout => \A:Q1[29]~1_combout\,
	cout => \A:Q1[29]~2\);

-- Location: FF_X30_Y3_N27
\A:Q1[29]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[29]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[29]~q\);

-- Location: LCCOMB_X30_Y3_N28
\A:Q1[30]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[30]~1_combout\ = (\A:Q1[30]~q\ & (!\A:Q1[29]~2\)) # (!\A:Q1[30]~q\ & ((\A:Q1[29]~2\) # (GND)))
-- \A:Q1[30]~2\ = CARRY((!\A:Q1[29]~2\) # (!\A:Q1[30]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \A:Q1[30]~q\,
	datad => VCC,
	cin => \A:Q1[29]~2\,
	combout => \A:Q1[30]~1_combout\,
	cout => \A:Q1[30]~2\);

-- Location: FF_X30_Y3_N29
\A:Q1[30]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[30]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[30]~q\);

-- Location: LCCOMB_X30_Y3_N30
\A:Q1[31]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \A:Q1[31]~1_combout\ = \A:Q1[31]~q\ $ (!\A:Q1[30]~2\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010110100101",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \A:Q1[31]~q\,
	cin => \A:Q1[30]~2\,
	combout => \A:Q1[31]~1_combout\);

-- Location: FF_X30_Y3_N31
\A:Q1[31]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \A:Q1[31]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \A:Q1[31]~q\);

-- Location: IOIBUF_X0_Y11_N8
\CLKBASE~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLKBASE,
	o => \CLKBASE~input_o\);

-- Location: CLKCTRL_G2
\CLKBASE~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \CLKBASE~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLKBASE~inputclkctrl_outclk\);

-- Location: LCCOMB_X8_Y23_N0
\B:Q1BASE[0]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[0]~0_combout\ = !\B:Q1BASE[0]~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \B:Q1BASE[0]~q\,
	combout => \B:Q1BASE[0]~0_combout\);

-- Location: FF_X8_Y23_N1
\B:Q1BASE[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[0]~0_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[0]~q\);

-- Location: LCCOMB_X8_Y23_N2
\B:Q1BASE[1]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[1]~1_combout\ = (\B:Q1BASE[0]~q\ & (\B:Q1BASE[1]~q\ $ (VCC))) # (!\B:Q1BASE[0]~q\ & (\B:Q1BASE[1]~q\ & VCC))
-- \B:Q1BASE[1]~2\ = CARRY((\B:Q1BASE[0]~q\ & \B:Q1BASE[1]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110011010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[0]~q\,
	datab => \B:Q1BASE[1]~q\,
	datad => VCC,
	combout => \B:Q1BASE[1]~1_combout\,
	cout => \B:Q1BASE[1]~2\);

-- Location: FF_X8_Y23_N3
\B:Q1BASE[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[1]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[1]~q\);

-- Location: LCCOMB_X8_Y23_N4
\B:Q1BASE[2]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[2]~1_combout\ = (\B:Q1BASE[2]~q\ & (!\B:Q1BASE[1]~2\)) # (!\B:Q1BASE[2]~q\ & ((\B:Q1BASE[1]~2\) # (GND)))
-- \B:Q1BASE[2]~2\ = CARRY((!\B:Q1BASE[1]~2\) # (!\B:Q1BASE[2]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[2]~q\,
	datad => VCC,
	cin => \B:Q1BASE[1]~2\,
	combout => \B:Q1BASE[2]~1_combout\,
	cout => \B:Q1BASE[2]~2\);

-- Location: FF_X8_Y23_N5
\B:Q1BASE[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[2]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[2]~q\);

-- Location: LCCOMB_X8_Y23_N6
\B:Q1BASE[3]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[3]~1_combout\ = (\B:Q1BASE[3]~q\ & (\B:Q1BASE[2]~2\ $ (GND))) # (!\B:Q1BASE[3]~q\ & (!\B:Q1BASE[2]~2\ & VCC))
-- \B:Q1BASE[3]~2\ = CARRY((\B:Q1BASE[3]~q\ & !\B:Q1BASE[2]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[3]~q\,
	datad => VCC,
	cin => \B:Q1BASE[2]~2\,
	combout => \B:Q1BASE[3]~1_combout\,
	cout => \B:Q1BASE[3]~2\);

-- Location: FF_X8_Y23_N7
\B:Q1BASE[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[3]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[3]~q\);

-- Location: LCCOMB_X8_Y23_N8
\B:Q1BASE[4]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[4]~1_combout\ = (\B:Q1BASE[4]~q\ & (!\B:Q1BASE[3]~2\)) # (!\B:Q1BASE[4]~q\ & ((\B:Q1BASE[3]~2\) # (GND)))
-- \B:Q1BASE[4]~2\ = CARRY((!\B:Q1BASE[3]~2\) # (!\B:Q1BASE[4]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[4]~q\,
	datad => VCC,
	cin => \B:Q1BASE[3]~2\,
	combout => \B:Q1BASE[4]~1_combout\,
	cout => \B:Q1BASE[4]~2\);

-- Location: FF_X8_Y23_N9
\B:Q1BASE[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[4]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[4]~q\);

-- Location: LCCOMB_X8_Y23_N10
\B:Q1BASE[5]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[5]~1_combout\ = (\B:Q1BASE[5]~q\ & (\B:Q1BASE[4]~2\ $ (GND))) # (!\B:Q1BASE[5]~q\ & (!\B:Q1BASE[4]~2\ & VCC))
-- \B:Q1BASE[5]~2\ = CARRY((\B:Q1BASE[5]~q\ & !\B:Q1BASE[4]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[5]~q\,
	datad => VCC,
	cin => \B:Q1BASE[4]~2\,
	combout => \B:Q1BASE[5]~1_combout\,
	cout => \B:Q1BASE[5]~2\);

-- Location: FF_X8_Y23_N11
\B:Q1BASE[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[5]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[5]~q\);

-- Location: LCCOMB_X8_Y23_N12
\B:Q1BASE[6]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[6]~1_combout\ = (\B:Q1BASE[6]~q\ & (!\B:Q1BASE[5]~2\)) # (!\B:Q1BASE[6]~q\ & ((\B:Q1BASE[5]~2\) # (GND)))
-- \B:Q1BASE[6]~2\ = CARRY((!\B:Q1BASE[5]~2\) # (!\B:Q1BASE[6]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[6]~q\,
	datad => VCC,
	cin => \B:Q1BASE[5]~2\,
	combout => \B:Q1BASE[6]~1_combout\,
	cout => \B:Q1BASE[6]~2\);

-- Location: FF_X8_Y23_N13
\B:Q1BASE[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[6]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[6]~q\);

-- Location: LCCOMB_X8_Y23_N14
\B:Q1BASE[7]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[7]~1_combout\ = (\B:Q1BASE[7]~q\ & (\B:Q1BASE[6]~2\ $ (GND))) # (!\B:Q1BASE[7]~q\ & (!\B:Q1BASE[6]~2\ & VCC))
-- \B:Q1BASE[7]~2\ = CARRY((\B:Q1BASE[7]~q\ & !\B:Q1BASE[6]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[7]~q\,
	datad => VCC,
	cin => \B:Q1BASE[6]~2\,
	combout => \B:Q1BASE[7]~1_combout\,
	cout => \B:Q1BASE[7]~2\);

-- Location: FF_X8_Y23_N15
\B:Q1BASE[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[7]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[7]~q\);

-- Location: LCCOMB_X8_Y23_N16
\B:Q1BASE[8]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[8]~1_combout\ = (\B:Q1BASE[8]~q\ & (!\B:Q1BASE[7]~2\)) # (!\B:Q1BASE[8]~q\ & ((\B:Q1BASE[7]~2\) # (GND)))
-- \B:Q1BASE[8]~2\ = CARRY((!\B:Q1BASE[7]~2\) # (!\B:Q1BASE[8]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[8]~q\,
	datad => VCC,
	cin => \B:Q1BASE[7]~2\,
	combout => \B:Q1BASE[8]~1_combout\,
	cout => \B:Q1BASE[8]~2\);

-- Location: FF_X8_Y23_N17
\B:Q1BASE[8]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[8]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[8]~q\);

-- Location: LCCOMB_X8_Y23_N18
\B:Q1BASE[9]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[9]~1_combout\ = (\B:Q1BASE[9]~q\ & (\B:Q1BASE[8]~2\ $ (GND))) # (!\B:Q1BASE[9]~q\ & (!\B:Q1BASE[8]~2\ & VCC))
-- \B:Q1BASE[9]~2\ = CARRY((\B:Q1BASE[9]~q\ & !\B:Q1BASE[8]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[9]~q\,
	datad => VCC,
	cin => \B:Q1BASE[8]~2\,
	combout => \B:Q1BASE[9]~1_combout\,
	cout => \B:Q1BASE[9]~2\);

-- Location: FF_X8_Y23_N19
\B:Q1BASE[9]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[9]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[9]~q\);

-- Location: LCCOMB_X8_Y23_N20
\B:Q1BASE[10]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[10]~1_combout\ = (\B:Q1BASE[10]~q\ & (!\B:Q1BASE[9]~2\)) # (!\B:Q1BASE[10]~q\ & ((\B:Q1BASE[9]~2\) # (GND)))
-- \B:Q1BASE[10]~2\ = CARRY((!\B:Q1BASE[9]~2\) # (!\B:Q1BASE[10]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[10]~q\,
	datad => VCC,
	cin => \B:Q1BASE[9]~2\,
	combout => \B:Q1BASE[10]~1_combout\,
	cout => \B:Q1BASE[10]~2\);

-- Location: FF_X8_Y23_N21
\B:Q1BASE[10]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[10]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[10]~q\);

-- Location: LCCOMB_X8_Y23_N22
\B:Q1BASE[11]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[11]~1_combout\ = (\B:Q1BASE[11]~q\ & (\B:Q1BASE[10]~2\ $ (GND))) # (!\B:Q1BASE[11]~q\ & (!\B:Q1BASE[10]~2\ & VCC))
-- \B:Q1BASE[11]~2\ = CARRY((\B:Q1BASE[11]~q\ & !\B:Q1BASE[10]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[11]~q\,
	datad => VCC,
	cin => \B:Q1BASE[10]~2\,
	combout => \B:Q1BASE[11]~1_combout\,
	cout => \B:Q1BASE[11]~2\);

-- Location: FF_X8_Y23_N23
\B:Q1BASE[11]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[11]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[11]~q\);

-- Location: LCCOMB_X8_Y23_N24
\B:Q1BASE[12]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[12]~1_combout\ = (\B:Q1BASE[12]~q\ & (!\B:Q1BASE[11]~2\)) # (!\B:Q1BASE[12]~q\ & ((\B:Q1BASE[11]~2\) # (GND)))
-- \B:Q1BASE[12]~2\ = CARRY((!\B:Q1BASE[11]~2\) # (!\B:Q1BASE[12]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[12]~q\,
	datad => VCC,
	cin => \B:Q1BASE[11]~2\,
	combout => \B:Q1BASE[12]~1_combout\,
	cout => \B:Q1BASE[12]~2\);

-- Location: FF_X8_Y23_N25
\B:Q1BASE[12]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[12]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[12]~q\);

-- Location: LCCOMB_X8_Y23_N26
\B:Q1BASE[13]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[13]~1_combout\ = (\B:Q1BASE[13]~q\ & (\B:Q1BASE[12]~2\ $ (GND))) # (!\B:Q1BASE[13]~q\ & (!\B:Q1BASE[12]~2\ & VCC))
-- \B:Q1BASE[13]~2\ = CARRY((\B:Q1BASE[13]~q\ & !\B:Q1BASE[12]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[13]~q\,
	datad => VCC,
	cin => \B:Q1BASE[12]~2\,
	combout => \B:Q1BASE[13]~1_combout\,
	cout => \B:Q1BASE[13]~2\);

-- Location: FF_X8_Y23_N27
\B:Q1BASE[13]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[13]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[13]~q\);

-- Location: LCCOMB_X8_Y23_N28
\B:Q1BASE[14]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[14]~1_combout\ = (\B:Q1BASE[14]~q\ & (!\B:Q1BASE[13]~2\)) # (!\B:Q1BASE[14]~q\ & ((\B:Q1BASE[13]~2\) # (GND)))
-- \B:Q1BASE[14]~2\ = CARRY((!\B:Q1BASE[13]~2\) # (!\B:Q1BASE[14]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[14]~q\,
	datad => VCC,
	cin => \B:Q1BASE[13]~2\,
	combout => \B:Q1BASE[14]~1_combout\,
	cout => \B:Q1BASE[14]~2\);

-- Location: FF_X8_Y23_N29
\B:Q1BASE[14]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[14]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[14]~q\);

-- Location: LCCOMB_X8_Y23_N30
\B:Q1BASE[15]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[15]~1_combout\ = (\B:Q1BASE[15]~q\ & (\B:Q1BASE[14]~2\ $ (GND))) # (!\B:Q1BASE[15]~q\ & (!\B:Q1BASE[14]~2\ & VCC))
-- \B:Q1BASE[15]~2\ = CARRY((\B:Q1BASE[15]~q\ & !\B:Q1BASE[14]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[15]~q\,
	datad => VCC,
	cin => \B:Q1BASE[14]~2\,
	combout => \B:Q1BASE[15]~1_combout\,
	cout => \B:Q1BASE[15]~2\);

-- Location: FF_X8_Y23_N31
\B:Q1BASE[15]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[15]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[15]~q\);

-- Location: LCCOMB_X8_Y22_N0
\B:Q1BASE[16]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[16]~1_combout\ = (\B:Q1BASE[16]~q\ & (!\B:Q1BASE[15]~2\)) # (!\B:Q1BASE[16]~q\ & ((\B:Q1BASE[15]~2\) # (GND)))
-- \B:Q1BASE[16]~2\ = CARRY((!\B:Q1BASE[15]~2\) # (!\B:Q1BASE[16]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[16]~q\,
	datad => VCC,
	cin => \B:Q1BASE[15]~2\,
	combout => \B:Q1BASE[16]~1_combout\,
	cout => \B:Q1BASE[16]~2\);

-- Location: FF_X8_Y22_N1
\B:Q1BASE[16]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[16]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[16]~q\);

-- Location: LCCOMB_X8_Y22_N2
\B:Q1BASE[17]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[17]~1_combout\ = (\B:Q1BASE[17]~q\ & (\B:Q1BASE[16]~2\ $ (GND))) # (!\B:Q1BASE[17]~q\ & (!\B:Q1BASE[16]~2\ & VCC))
-- \B:Q1BASE[17]~2\ = CARRY((\B:Q1BASE[17]~q\ & !\B:Q1BASE[16]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[17]~q\,
	datad => VCC,
	cin => \B:Q1BASE[16]~2\,
	combout => \B:Q1BASE[17]~1_combout\,
	cout => \B:Q1BASE[17]~2\);

-- Location: FF_X8_Y22_N3
\B:Q1BASE[17]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[17]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[17]~q\);

-- Location: LCCOMB_X8_Y22_N4
\B:Q1BASE[18]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[18]~1_combout\ = (\B:Q1BASE[18]~q\ & (!\B:Q1BASE[17]~2\)) # (!\B:Q1BASE[18]~q\ & ((\B:Q1BASE[17]~2\) # (GND)))
-- \B:Q1BASE[18]~2\ = CARRY((!\B:Q1BASE[17]~2\) # (!\B:Q1BASE[18]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[18]~q\,
	datad => VCC,
	cin => \B:Q1BASE[17]~2\,
	combout => \B:Q1BASE[18]~1_combout\,
	cout => \B:Q1BASE[18]~2\);

-- Location: FF_X8_Y22_N5
\B:Q1BASE[18]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[18]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[18]~q\);

-- Location: LCCOMB_X8_Y22_N6
\B:Q1BASE[19]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[19]~1_combout\ = (\B:Q1BASE[19]~q\ & (\B:Q1BASE[18]~2\ $ (GND))) # (!\B:Q1BASE[19]~q\ & (!\B:Q1BASE[18]~2\ & VCC))
-- \B:Q1BASE[19]~2\ = CARRY((\B:Q1BASE[19]~q\ & !\B:Q1BASE[18]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[19]~q\,
	datad => VCC,
	cin => \B:Q1BASE[18]~2\,
	combout => \B:Q1BASE[19]~1_combout\,
	cout => \B:Q1BASE[19]~2\);

-- Location: FF_X8_Y22_N7
\B:Q1BASE[19]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[19]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[19]~q\);

-- Location: LCCOMB_X8_Y22_N8
\B:Q1BASE[20]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[20]~1_combout\ = (\B:Q1BASE[20]~q\ & (!\B:Q1BASE[19]~2\)) # (!\B:Q1BASE[20]~q\ & ((\B:Q1BASE[19]~2\) # (GND)))
-- \B:Q1BASE[20]~2\ = CARRY((!\B:Q1BASE[19]~2\) # (!\B:Q1BASE[20]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[20]~q\,
	datad => VCC,
	cin => \B:Q1BASE[19]~2\,
	combout => \B:Q1BASE[20]~1_combout\,
	cout => \B:Q1BASE[20]~2\);

-- Location: FF_X8_Y22_N9
\B:Q1BASE[20]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[20]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[20]~q\);

-- Location: LCCOMB_X8_Y22_N10
\B:Q1BASE[21]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[21]~1_combout\ = (\B:Q1BASE[21]~q\ & (\B:Q1BASE[20]~2\ $ (GND))) # (!\B:Q1BASE[21]~q\ & (!\B:Q1BASE[20]~2\ & VCC))
-- \B:Q1BASE[21]~2\ = CARRY((\B:Q1BASE[21]~q\ & !\B:Q1BASE[20]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[21]~q\,
	datad => VCC,
	cin => \B:Q1BASE[20]~2\,
	combout => \B:Q1BASE[21]~1_combout\,
	cout => \B:Q1BASE[21]~2\);

-- Location: FF_X8_Y22_N11
\B:Q1BASE[21]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[21]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[21]~q\);

-- Location: LCCOMB_X8_Y22_N12
\B:Q1BASE[22]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[22]~1_combout\ = (\B:Q1BASE[22]~q\ & (!\B:Q1BASE[21]~2\)) # (!\B:Q1BASE[22]~q\ & ((\B:Q1BASE[21]~2\) # (GND)))
-- \B:Q1BASE[22]~2\ = CARRY((!\B:Q1BASE[21]~2\) # (!\B:Q1BASE[22]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[22]~q\,
	datad => VCC,
	cin => \B:Q1BASE[21]~2\,
	combout => \B:Q1BASE[22]~1_combout\,
	cout => \B:Q1BASE[22]~2\);

-- Location: FF_X8_Y22_N13
\B:Q1BASE[22]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[22]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[22]~q\);

-- Location: LCCOMB_X8_Y22_N14
\B:Q1BASE[23]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[23]~1_combout\ = (\B:Q1BASE[23]~q\ & (\B:Q1BASE[22]~2\ $ (GND))) # (!\B:Q1BASE[23]~q\ & (!\B:Q1BASE[22]~2\ & VCC))
-- \B:Q1BASE[23]~2\ = CARRY((\B:Q1BASE[23]~q\ & !\B:Q1BASE[22]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[23]~q\,
	datad => VCC,
	cin => \B:Q1BASE[22]~2\,
	combout => \B:Q1BASE[23]~1_combout\,
	cout => \B:Q1BASE[23]~2\);

-- Location: FF_X8_Y22_N15
\B:Q1BASE[23]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[23]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[23]~q\);

-- Location: LCCOMB_X8_Y22_N16
\B:Q1BASE[24]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[24]~1_combout\ = (\B:Q1BASE[24]~q\ & (!\B:Q1BASE[23]~2\)) # (!\B:Q1BASE[24]~q\ & ((\B:Q1BASE[23]~2\) # (GND)))
-- \B:Q1BASE[24]~2\ = CARRY((!\B:Q1BASE[23]~2\) # (!\B:Q1BASE[24]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[24]~q\,
	datad => VCC,
	cin => \B:Q1BASE[23]~2\,
	combout => \B:Q1BASE[24]~1_combout\,
	cout => \B:Q1BASE[24]~2\);

-- Location: FF_X8_Y22_N17
\B:Q1BASE[24]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[24]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[24]~q\);

-- Location: LCCOMB_X8_Y22_N18
\B:Q1BASE[25]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[25]~1_combout\ = (\B:Q1BASE[25]~q\ & (\B:Q1BASE[24]~2\ $ (GND))) # (!\B:Q1BASE[25]~q\ & (!\B:Q1BASE[24]~2\ & VCC))
-- \B:Q1BASE[25]~2\ = CARRY((\B:Q1BASE[25]~q\ & !\B:Q1BASE[24]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[25]~q\,
	datad => VCC,
	cin => \B:Q1BASE[24]~2\,
	combout => \B:Q1BASE[25]~1_combout\,
	cout => \B:Q1BASE[25]~2\);

-- Location: FF_X8_Y22_N19
\B:Q1BASE[25]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[25]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[25]~q\);

-- Location: LCCOMB_X8_Y22_N20
\B:Q1BASE[26]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[26]~1_combout\ = (\B:Q1BASE[26]~q\ & (!\B:Q1BASE[25]~2\)) # (!\B:Q1BASE[26]~q\ & ((\B:Q1BASE[25]~2\) # (GND)))
-- \B:Q1BASE[26]~2\ = CARRY((!\B:Q1BASE[25]~2\) # (!\B:Q1BASE[26]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[26]~q\,
	datad => VCC,
	cin => \B:Q1BASE[25]~2\,
	combout => \B:Q1BASE[26]~1_combout\,
	cout => \B:Q1BASE[26]~2\);

-- Location: FF_X8_Y22_N21
\B:Q1BASE[26]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[26]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[26]~q\);

-- Location: LCCOMB_X8_Y22_N22
\B:Q1BASE[27]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[27]~1_combout\ = (\B:Q1BASE[27]~q\ & (\B:Q1BASE[26]~2\ $ (GND))) # (!\B:Q1BASE[27]~q\ & (!\B:Q1BASE[26]~2\ & VCC))
-- \B:Q1BASE[27]~2\ = CARRY((\B:Q1BASE[27]~q\ & !\B:Q1BASE[26]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[27]~q\,
	datad => VCC,
	cin => \B:Q1BASE[26]~2\,
	combout => \B:Q1BASE[27]~1_combout\,
	cout => \B:Q1BASE[27]~2\);

-- Location: FF_X8_Y22_N23
\B:Q1BASE[27]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[27]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[27]~q\);

-- Location: LCCOMB_X8_Y22_N24
\B:Q1BASE[28]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[28]~1_combout\ = (\B:Q1BASE[28]~q\ & (!\B:Q1BASE[27]~2\)) # (!\B:Q1BASE[28]~q\ & ((\B:Q1BASE[27]~2\) # (GND)))
-- \B:Q1BASE[28]~2\ = CARRY((!\B:Q1BASE[27]~2\) # (!\B:Q1BASE[28]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[28]~q\,
	datad => VCC,
	cin => \B:Q1BASE[27]~2\,
	combout => \B:Q1BASE[28]~1_combout\,
	cout => \B:Q1BASE[28]~2\);

-- Location: FF_X8_Y22_N25
\B:Q1BASE[28]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[28]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[28]~q\);

-- Location: LCCOMB_X8_Y22_N26
\B:Q1BASE[29]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[29]~1_combout\ = (\B:Q1BASE[29]~q\ & (\B:Q1BASE[28]~2\ $ (GND))) # (!\B:Q1BASE[29]~q\ & (!\B:Q1BASE[28]~2\ & VCC))
-- \B:Q1BASE[29]~2\ = CARRY((\B:Q1BASE[29]~q\ & !\B:Q1BASE[28]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[29]~q\,
	datad => VCC,
	cin => \B:Q1BASE[28]~2\,
	combout => \B:Q1BASE[29]~1_combout\,
	cout => \B:Q1BASE[29]~2\);

-- Location: FF_X8_Y22_N27
\B:Q1BASE[29]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[29]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[29]~q\);

-- Location: LCCOMB_X8_Y22_N28
\B:Q1BASE[30]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[30]~1_combout\ = (\B:Q1BASE[30]~q\ & (!\B:Q1BASE[29]~2\)) # (!\B:Q1BASE[30]~q\ & ((\B:Q1BASE[29]~2\) # (GND)))
-- \B:Q1BASE[30]~2\ = CARRY((!\B:Q1BASE[29]~2\) # (!\B:Q1BASE[30]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \B:Q1BASE[30]~q\,
	datad => VCC,
	cin => \B:Q1BASE[29]~2\,
	combout => \B:Q1BASE[30]~1_combout\,
	cout => \B:Q1BASE[30]~2\);

-- Location: FF_X8_Y22_N29
\B:Q1BASE[30]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[30]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[30]~q\);

-- Location: LCCOMB_X8_Y22_N30
\B:Q1BASE[31]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \B:Q1BASE[31]~1_combout\ = \B:Q1BASE[31]~q\ $ (!\B:Q1BASE[30]~2\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010110100101",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \B:Q1BASE[31]~q\,
	cin => \B:Q1BASE[30]~2\,
	combout => \B:Q1BASE[31]~1_combout\);

-- Location: FF_X8_Y22_N31
\B:Q1BASE[31]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLKBASE~inputclkctrl_outclk\,
	d => \B:Q1BASE[31]~1_combout\,
	clrn => \CLR~inputclkctrl_outclk\,
	ena => \A:Q1[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \B:Q1BASE[31]~q\);

ww_Q(0) <= \Q[0]~output_o\;

ww_Q(1) <= \Q[1]~output_o\;

ww_Q(2) <= \Q[2]~output_o\;

ww_Q(3) <= \Q[3]~output_o\;

ww_Q(4) <= \Q[4]~output_o\;

ww_Q(5) <= \Q[5]~output_o\;

ww_Q(6) <= \Q[6]~output_o\;

ww_Q(7) <= \Q[7]~output_o\;

ww_Q(8) <= \Q[8]~output_o\;

ww_Q(9) <= \Q[9]~output_o\;

ww_Q(10) <= \Q[10]~output_o\;

ww_Q(11) <= \Q[11]~output_o\;

ww_Q(12) <= \Q[12]~output_o\;

ww_Q(13) <= \Q[13]~output_o\;

ww_Q(14) <= \Q[14]~output_o\;

ww_Q(15) <= \Q[15]~output_o\;

ww_Q(16) <= \Q[16]~output_o\;

ww_Q(17) <= \Q[17]~output_o\;

ww_Q(18) <= \Q[18]~output_o\;

ww_Q(19) <= \Q[19]~output_o\;

ww_Q(20) <= \Q[20]~output_o\;

ww_Q(21) <= \Q[21]~output_o\;

ww_Q(22) <= \Q[22]~output_o\;

ww_Q(23) <= \Q[23]~output_o\;

ww_Q(24) <= \Q[24]~output_o\;

ww_Q(25) <= \Q[25]~output_o\;

ww_Q(26) <= \Q[26]~output_o\;

ww_Q(27) <= \Q[27]~output_o\;

ww_Q(28) <= \Q[28]~output_o\;

ww_Q(29) <= \Q[29]~output_o\;

ww_Q(30) <= \Q[30]~output_o\;

ww_Q(31) <= \Q[31]~output_o\;

ww_QBASE(0) <= \QBASE[0]~output_o\;

ww_QBASE(1) <= \QBASE[1]~output_o\;

ww_QBASE(2) <= \QBASE[2]~output_o\;

ww_QBASE(3) <= \QBASE[3]~output_o\;

ww_QBASE(4) <= \QBASE[4]~output_o\;

ww_QBASE(5) <= \QBASE[5]~output_o\;

ww_QBASE(6) <= \QBASE[6]~output_o\;

ww_QBASE(7) <= \QBASE[7]~output_o\;

ww_QBASE(8) <= \QBASE[8]~output_o\;

ww_QBASE(9) <= \QBASE[9]~output_o\;

ww_QBASE(10) <= \QBASE[10]~output_o\;

ww_QBASE(11) <= \QBASE[11]~output_o\;

ww_QBASE(12) <= \QBASE[12]~output_o\;

ww_QBASE(13) <= \QBASE[13]~output_o\;

ww_QBASE(14) <= \QBASE[14]~output_o\;

ww_QBASE(15) <= \QBASE[15]~output_o\;

ww_QBASE(16) <= \QBASE[16]~output_o\;

ww_QBASE(17) <= \QBASE[17]~output_o\;

ww_QBASE(18) <= \QBASE[18]~output_o\;

ww_QBASE(19) <= \QBASE[19]~output_o\;

ww_QBASE(20) <= \QBASE[20]~output_o\;

ww_QBASE(21) <= \QBASE[21]~output_o\;

ww_QBASE(22) <= \QBASE[22]~output_o\;

ww_QBASE(23) <= \QBASE[23]~output_o\;

ww_QBASE(24) <= \QBASE[24]~output_o\;

ww_QBASE(25) <= \QBASE[25]~output_o\;

ww_QBASE(26) <= \QBASE[26]~output_o\;

ww_QBASE(27) <= \QBASE[27]~output_o\;

ww_QBASE(28) <= \QBASE[28]~output_o\;

ww_QBASE(29) <= \QBASE[29]~output_o\;

ww_QBASE(30) <= \QBASE[30]~output_o\;

ww_QBASE(31) <= \QBASE[31]~output_o\;
END structure;


