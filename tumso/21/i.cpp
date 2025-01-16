#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <queue>
#include <tuple>

using namespace std;

const double INF = numeric_limits<double>::infinity();

// Structure to store a point (x, y)
struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};

// Function to calculate the Euclidean distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to check if two line segments (p1, p2) and (q1, q2) intersect
bool onSegment(Point p, Point q, Point r) {
    return r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) && r.y <= max(p.y, q.y) && r.y >= min(p.y, q.y);
}

double crossProduct(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool doIntersect(Point p1, Point p2, Point q1, Point q2) {
    double o1 = crossProduct(p1, p2, q1);
    double o2 = crossProduct(p1, p2, q2);
    double o3 = crossProduct(q1, q2, p1);
    double o4 = crossProduct(q1, q2, p2);

    if (o1 * o2 < 0 && o3 * o4 < 0) return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, p2, q2)) return true;
    if (o3 == 0 && onSegment(q1, q2, p1)) return true;
    if (o4 == 0 && onSegment(q1, q2, p2)) return true;

    return false;
}

// Function to check if the line segment from (xs, ys) to (xt, yt) intersects any fence
bool isBlocked(Point start, Point end, vector<pair<Point, Point>> &fences) {
    for (auto &fence : fences) {
        if (doIntersect(start, end, fence.first, fence.second)) {
            return true;
        }
    }
    return false;
}

// Dijkstra-like approach to find the shortest path between start and end
double findShortestPath(Point start, Point end, vector<Point>& points, vector<pair<Point, Point>>& fences) {
    int n = points.size();
    vector<vector<double>> dist(n, vector<double>(n, INF)); // Distance matrix
    
    // Build the graph by checking all point-to-point connections
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!isBlocked(points[i], points[j], fences)) {
                double d = distance(points[i], points[j]);
                dist[i][j] = dist[j][i] = d;
            }
        }
    }

    // Use a priority queue for Dijkstra's algorithm
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq; // (distance, node)
    vector<double> shortest(n, INF);
    int startIdx = -1, endIdx = -1;
    
    // Find the indices for the start and end points
    for (int i = 0; i < n; ++i) {
        if (points[i].x == start.x && points[i].y == start.y) {
            startIdx = i;
        }
        if (points[i].x == end.x && points[i].y == end.y) {
            endIdx = i;
        }
    }
    
    if (startIdx == -1 || endIdx == -1) {
        return -1; // If start or end point doesn't exist
    }

    pq.push({0.0, startIdx});
    shortest[startIdx] = 0.0;

    while (!pq.empty()) {
        auto [curDist, u] = pq.top();
        pq.pop();

        if (curDist > shortest[u]) continue;

        for (int v = 0; v < n; ++v) {
            if (dist[u][v] < INF) {
                double newDist = curDist + dist[u][v];
                if (newDist < shortest[v]) {
                    shortest[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }

    return shortest[endIdx] == INF ? -1 : shortest[endIdx];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<pair<Point, Point>> fences(n);
    for (int i = 0; i < n; ++i) {
        cin >> fences[i].first.x >> fences[i].first.y >> fences[i].second.x >> fences[i].second.y;
    }

    while (q--) {
        Point start, end;
        cin >> start.x >> start.y >> end.x >> end.y;

        // Collect all points
        vector<Point> points = {start, end};
        for (const auto& fence : fences) {
            points.push_back(fence.first);
            points.push_back(fence.second);
        }

        double dist = findShortestPath(start, end, points, fences);
        if (dist == -1) {
            cout << "-1\n";
        } else {
            cout.precision(12);
            cout << fixed << dist << '\n';
        }
    }

    return 0;
}
