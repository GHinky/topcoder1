
class Trainyard {
public:
  int reachableSquares(vector <string> layout, int fuel) {
    memset(seen, 0, sizeof(seen));
    memset(seenfuel, 0, sizeof(seenfuel));
    g = layout;
    for (int y = 0; y < g.size(); y++)
      for (int x = 0; x < g[0].size(); x++)
	if (g[y][x] == 'S') {
	  for (int d = 0; d < 4; d++)
	    doit(x, y, d, fuel);
	}
    int ret = 0;
    for (int y = 0; y < g.size(); y++)
      for (int x = 0; x < g[0].size(); x++)
	if (seen[y][x]) ret++;
    return ret;
  }
};
 
 
