import java.util.ArrayList;
import java.util.List;

public class Main {
    public static int solution(int distance, int n, List<List<Integer>> gas_stations) {
        if (gas_stations == null || gas_stations.size() != n) {
            return -1; // Return -1 if input is not as expected
        }

        // Filter out invalid gas stations and sort by distance
        List<Node> stations = new ArrayList<>();
        for (List<Integer> station : gas_stations) {
            if (station.size() >= 2) {
                stations.add(new Node(station.get(0), station.get(1)));
            }
        }
        
        // Sort by distance first, then by cost
        stations.sort((o1, o2) -> {
            if (o1.a != o2.a) {
                return o1.a - o2.a;
            } else {
                return o1.b - o2.b;
            }
        });

        // Add the end point and boundary points as per the original algorithm
        stations.add(0, new Node(0, Integer.MAX_VALUE));
        stations.add(new Node(distance + 200, 0));

        // Perform depth-first search
        int ans = Integer.MAX_VALUE;
        ans = dfs(0, 200, 0, stations, ans);

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private static int dfs(int x, int now, int tot, List<Node> a, int ans) {
        int fg = 0;
        int n = a.size() - 1;
        if (x == n) {
            ans = Math.min(ans, tot);
            return ans;
        }

        int j = x + 1, k = Integer.MAX_VALUE, dd = 0;
        for (int i = 0; i <= now && j <= n; ++i) {
            while (a.get(x).a + i >= a.get(j).a && j <= n) {
                if (a.get(j).b <= k) {
                    k = a.get(j).b;
                    dd = j;
                    fg = 1;
                }
                ++j;
            }
        }

        if (k <= a.get(x).b) {
            ans = dfs(dd, now - (a.get(dd).a - a.get(x).a), tot + (a.get(dd).a - a.get(x).a) * a.get(x).b, a, ans);
        } else {
            j = x + 1;
            k = Integer.MAX_VALUE;
            dd = 0;
            int mx = x == 1 ? 200 : 400;
            for (int i = 0; i <= mx && j <= n; ++i) {
                while (a.get(x).a + i >= a.get(j).a && j <= n) {
                    if (a.get(j).b <= k) {
                        k = a.get(j).b;
                        dd = j;
                        fg = 1;
                    }
                    ++j;
                }
            }

            if(fg != 1) return -1;
            if (k <= a.get(x).b) {
                ans = dfs(dd, 0, tot + (a.get(dd).a - now - a.get(x).a) * a.get(x).b, a, ans);
            } else {
                ans = dfs(dd, 400 - (a.get(dd).a - a.get(x).a), tot + (400 - now) * a.get(x).b, a, ans);
            }
        }
        return ans;
    }

    static class Node {
        int a, b;
        public Node(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> gasStations1 = new ArrayList<>();
        gasStations1.add(List.of(100, 1));
        gasStations1.add(List.of(200, 30));
        gasStations1.add(List.of(400, 40));
        gasStations1.add(List.of(300, 20));

        List<List<Integer>> gasStations2 = new ArrayList<>();
        gasStations2.add(List.of(100, 999));
        gasStations2.add(List.of(150, 888));
        gasStations2.add(List.of(200, 777));
        gasStations2.add(List.of(300, 999));
        gasStations2.add(List.of(400, 1009));
        gasStations2.add(List.of(450, 1019));
        gasStations2.add(List.of(500, 1399));

        List<List<Integer>> gasStations3 = new ArrayList<>();
        gasStations3.add(List.of(101));
        gasStations3.add(List.of(100, 100));
        gasStations3.add(List.of(102, 1));

        List<List<Integer>> gasStations4 = new ArrayList<>();
        gasStations4.add(List.of(34, 1));
        gasStations4.add(List.of(105, 9));
        gasStations4.add(List.of(9, 10));
        gasStations4.add(List.of(134, 66));
        gasStations4.add(List.of(215, 90));
        gasStations4.add(List.of(999, 1999));
        gasStations4.add(List.of(49, 0));
        gasStations4.add(List.of(10, 1999));
        gasStations4.add(List.of(200, 2));
        gasStations4.add(List.of(300, 500));
        gasStations4.add(List.of(12, 34));
        gasStations4.add(List.of(1, 23));
        gasStations4.add(List.of(46, 20));
        gasStations4.add(List.of(80, 12));
        gasStations4.add(List.of(1, 1999));
        gasStations4.add(List.of(90, 33));
        gasStations4.add(List.of(101, 23));
        gasStations4.add(List.of(34, 88));
        gasStations4.add(List.of(103, 0));
        gasStations4.add(List.of(1, 1));

        System.out.println(solution(500, 4, gasStations1) == 4300);
        System.out.println(solution(500, 7, gasStations2) == 410700);
        System.out.println(solution(500, 3, gasStations3) == -1);
        System.out.println(solution(100, 20, gasStations4) == 0);
        System.out.println(solution(100, 0, new ArrayList<>()) == -1);
    }
}
