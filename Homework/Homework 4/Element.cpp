//Oneal Abdulrahim
//CSCE 121-504
//Due: March 3, 2016
//Element.cpp (hw4pr1)

#include <vector>
#include <string>

class Element {

    int atomic;
	std::string symbol;
	double mass;
	
	public:
		Element() {
		    atomic = 0;
		    symbol = "!";
		    mass = 0;
		}
		
		Element(int m_atomic, std::string m_symbol, double m_mass) {
		    atomic = m_atomic;
		    symbol = m_symbol;
		    mass = m_mass;
		}
		
		std::string get_symbol() {
			return symbol;
		}
		
		int get_atomic() {
			return atomic;
		}
		
		double get_mass() {
			return mass;
		}
};

//Nice big vector of all elements so we do not have to rely on user input for atomic number or mass number!
std::vector<Element> elements = {
        Element()                        ,
        Element(1,     "H",    1.007825 ),
        Element(2,     "He",   4.00260  ),
        Element(3,     "Li",   6.941    ),
        Element(4,     "Be",   9.01218  ),
        Element(5,     "B",    10.81    ),
        Element(6,     "C",    12.011   ),
        Element(7,     "N",    14.0067  ),
        Element(8,     "O",    15.999   ),
        Element(9,     "F",    18.99840 ),
        Element(10,    "Ne",   20.179   ),
        Element(11,    "Na",   22.98977 ),
        Element(12,    "Mg",   24.305   ),
        Element(13,    "Al",   26.98154 ),
        Element(14,    "Si",   28.0855  ),
        Element(15,    "P",    30.973   ),
        Element(16,    "S",    32.06    ),
        Element(17,    "Cl",   35.453   ),
        Element(18,    "Ar",   39.948   ),
        Element(19,    "K",    39.0983  ),
        Element(20,    "Ca",   40.08    ),
        Element(21,    "Sc",   44.9559  ),
        Element(22,    "Ti",   47.90    ),
        Element(23,    "V",    50.9414  ),
        Element(24,    "Cr",   51.996   ),
        Element(25,    "Mn",   54.9380  ),
        Element(26,    "Fe",   55.85    ),
        Element(27,    "Co",   58.9332  ),
        Element(28,    "Ni",   58.71    ),
        Element(29,    "Cu",   63.546   ),
        Element(30,    "Zn",   65.37    ),
        Element(31,    "Ga",   69.72    ),
        Element(32,    "Ge",   72.59    ),
        Element(33,    "As",   74.9216  ),
        Element(34,    "Se",   78.96    ),
        Element(35,    "Br",   79.904   ),
        Element(36,    "Kr",   83.80    ),
        Element(37,    "Rb",   85.4678  ),
        Element(38,    "Sr",   87.62    ),
        Element(39,    "Y",    88.9059  ),
        Element(40,    "Zr",   91.22    ),
        Element(41,    "Nb",   92.91    ),
        Element(42,    "Mo",   95.94    ),
        Element(43,    "Tc",   99.0     ),
        Element(44,    "Ru",   101.1    ),
        Element(45,    "Rh",   102.91   ),
        Element(46,    "Pd",   106.42   ),
        Element(47,    "Ag",   107.87   ),
        Element(48,    "Cd",   112.4    ),
        Element(49,    "In",   114.82   ),
        Element(50,    "Sn",   118.69   ),
        Element(51,    "Sb",   121.75   ),
        Element(52,    "Te",   127.6    ),
        Element(53,    "I",    126.9045 ),
        Element(54,    "Xe",   131.29   ),
        Element(55,    "Cs",   132.9054 ),
        Element(56,    "Ba",   137.33   ),
        Element(57,    "La",   138.91   ),
        Element(58,    "Ce",   140.12   ),
        Element(59,    "Pr",   140.91   ),
        Element(60,    "Nd",   144.242  ),
        Element(61,    "Pm",   147.0    ),
        Element(62,    "Sm",   150.35   ),
        Element(63,    "Eu",   167.26   ),
        Element(64,    "Gd",   157.25   ),
        Element(65,    "Tb",   158.925  ),
        Element(66,    "Dy",   162.50   ),
        Element(67,    "Ho",   164.9    ),
        Element(68,    "Er",   167.26   ),
        Element(69,    "Tm",   168.93   ),
        Element(70,    "Yb",   173.04   ),
        Element(71,    "Lu",   174.97   ),
        Element(72,    "Hf",   178.49   ),
        Element(73,    "Ta",   180.95   ),
        Element(74,    "W",    183.85   ),
        Element(75,    "Re",   186.23   ),
        Element(76,    "Os",   190.2    ),
        Element(77,    "Ir",   192.2    ),
        Element(78,    "Pt",   195.09   ),
        Element(79,    "Au",   196.9655 ),
        Element(80,    "Hg",   200.59   ),
        Element(81,    "Tl",   204.383  ),
        Element(82,    "Pb",   207.2    ),
        Element(83,    "Bi",   208.9804 ),
        Element(84,    "Po",   210.0    ),
        Element(85,    "At",   210.0    ),
        Element(86,    "Rn",   222.0    ),
        Element(87,    "Fr",   233.0    ),
        Element(88,    "Ra",   226.0254 ),
        Element(89,    "Ac",   227.0    ),
        Element(90,    "Th",   232.04   ),
        Element(91,    "Pa",   231.0359 ),
        Element(92,    "U",    238.03   ),
        Element(93,    "Np",   237.0    ),
        Element(94,    "Pu",   244.0    ),
        Element(95,    "Am",   243.0    ),
        Element(96,    "Cm",   247.0    ),
        Element(97,    "Bk",   247.0    ),
        Element(98,    "Cf",   251.0    ),
        Element(99,    "Es",   254.0    ),
        Element(100,   "Fm",   257.0    ),
        Element(101,   "Md",   258.0    ),
        Element(102,   "No",   259.0    ),
        Element(103,   "Lr",   262.0    ),
        Element(104,   "Rf",   260.9    ),
        Element(105,   "Db",   261.9    ),
        Element(106,   "Sg",   262.94   ),
        Element(107,   "Bh",   262.0    ),
        Element(108,   "Hs",   264.8    ),
        Element(109,   "Mt",   265.9    ),
        Element(110,   "Ds",   261.9    ),
        Element(112,   "Uub",   276.8    ),
        Element(114,   "Uuq",   289.0    ),
        Element(116,   "Uuh",   0.0      )
};
