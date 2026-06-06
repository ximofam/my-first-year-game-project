

class Config {
public:
	static int getRow(char rank) {
		return '8' - rank;
	}
	static int getCol(char file) {
		return file - 'a';
	}
};