#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

#define INF_ 99999
class DijGraph {
public:
	DijGraph(int vCount) : vCount_(vCount) {
		adj_ = vector<vector<Edge>>(vCount);
	}
	void addEdge(int s, int e, int w) {
		if(s < vCount_ && s >= 0 && e < vCount_ && e >= 0) {
			adj_[s].emplace_back(s, e, w);
		}
	}
	int dijkstra(int s, int e) {
		vector<int> parent(vCount_);
		vector<Vertex> vertexes(vCount_);
		for(int i = 0; i < vCount_; ++i) {
			vertexes[i].id_ = i;
			vertexes[i].dist_ = INF_;
		}

		struct cmp {
			bool operator() (const Vertex& v1, const Vertex& v2) {
				return v1.dist_ > v2.dist_;
			}
		};
		priority_queue<Vertex, vector<Vertex>, cmp> queue;
		vector<bool> vis(vCount_, false);

		vertexes[s].dist_ = 0;
		queue.push(vertexes[s]);
		while (!queue.empty()) {
			Vertex minVertex = queue.top();
			queue.pop();
			if(minVertex.id_ == e) break;
			if(vis[minVertex.id_] == true) continue;
			vis[minVertex.id_] = true;
			for(int i = 0; i < adj_[minVertex.id_].size(); ++i) {
				Edge cur_edge = adj_[minVertex.id_].at(i);
				int nex_vid = cur_edge.eid_;
				if(!vis[nex_vid]) {
					if(minVertex.dist_ + cur_edge.w_ < vertexes[nex_vid].dist_) {
						vertexes[nex_vid].dist_ = minVertex.dist_ + cur_edge.w_;
						parent[nex_vid] = minVertex.id_;
						queue.push(vertexes[nex_vid]);
					}
				}
			}
		}

		//printRoute(s, e, parent);
		//cout << endl;
		return vertexes[e].dist_;
}
private:
	struct Edge {
		int sid_;
		int eid_;
		int w_;
		Edge() = default;
		Edge(int s, int e, int w) : sid_(s), eid_(e), w_(w) {}
	};
	struct Vertex {
		int id_;
		int dist_;
		Vertex() = default;
		Vertex(int id, int dist) : id_(id), dist_(dist) {}
	};
	vector<vector<Edge>> adj_; // 邻接表
	int vCount_;

	void printRoute(int s, int e, const vector<int>& parent) {
		if(s == e) {
			cout << s;
			return;
		}
		printRoute(s, parent[e], parent);
		cout << "->" << e;
	}
};

void printMat(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();
    for(int r = 0; r < row; ++r) {
        for(int c = 0; c < col; ++c) {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map;
    for(int i = 0; i < n; ++i) {
        vector<int> row(m, 0);
        int numOfM;
        cin >> numOfM;
        for(int i = 0; i < numOfM; ++i) {
            int temp;
            cin >> temp;
            row[temp-1] = 1;
        }
        map.push_back(row);
    }

    DijGraph g(n);

    // 建图
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(map[i][j] == 1) {
                for(int z = 0; z < n; ++z) {
                    if(map[z][j] == 1 && z != i) {
                        g.addEdge(i, z, 1);
                    }
                }
            }
        }
    }

    // calculate Upper triangle cost
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            cost[i][j] = g.dijkstra(i, j);
        }
    }
    // copy lower triangle
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            cost[i][j] = cost[j][i];
        }
    }

    printMat(cost);
    return 0;
}