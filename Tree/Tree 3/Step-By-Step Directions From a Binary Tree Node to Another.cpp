class Solution {
    struct Point {
        int x, y;
    };

    const int RIGHT = 1, LEFT = -1, ZERO = 0;

    int directionOfPoint(Point A, Point B, Point P) {
        B.x -= A.x;
        B.y -= A.y;
        P.x -= A.x;
        P.y -= A.y;

        int cross_product = B.x * P.y - B.y * P.x;

        if (cross_product > 0)
            return RIGHT;
        if (cross_product < 0)
            return LEFT;
        return ZERO;
    }

    struct Coordinates {
        int x, y;
    };

    struct Coordinates start_point, end_point;

    void findPath(TreeNode* root, int start, int destination, string start_path, string end_path, string &ans1, string &ans2, Coordinates org) {
        if (!root)
            return;

        if (root->val == start && ans1 == "") {
            start_point.x = org.x;
            start_point.y = org.y;
            ans1 = start_path;
        }

        if (root->val == destination && ans2 == "") {
            end_point.x = org.x;
            end_point.y = org.y;
            ans2 = end_path;
        }

        start_path += 'L';
        end_path += 'L';
        org.x++;
        org.y++;

        findPath(root->left, start, destination, start_path, end_path, ans1, ans2, org);

        org.x--;
        org.y--;
        org.x++;
        org.y--;

        start_path.pop_back();
        end_path.pop_back();

        start_path += 'R';
        end_path += 'R';

        findPath(root->right, start, destination, start_path, end_path, ans1, ans2, org);
    }

    TreeNode* lowestCommonAncestor(TreeNode* node, int start, int destination) {
        if (!node || node->val == start || node->val == destination)
            return node;

        TreeNode* left = lowestCommonAncestor(node->left, start, destination);
        TreeNode* right = lowestCommonAncestor(node->right, start, destination);

        if (left != nullptr && right != nullptr)
            return node;
        if (left == nullptr)
            return right;
        else
            return left;
    }

    void findDestinationPath(TreeNode* node, int destination, string path_so_far, string &result) {
        if (!node)
            return;

        if (node->val == destination && result == "") {
            result = path_so_far;
        }

        path_so_far += 'L';
        findDestinationPath(node->left, destination, path_so_far, result);

        path_so_far.pop_back();
        path_so_far += 'R';
        findDestinationPath(node->right, destination, path_so_far, result);
    }

public:
    string getDirections(TreeNode* root, int start, int destination) {
        TreeNode *intersection = lowestCommonAncestor(root, start, destination);
        string res = "";

        if (intersection->val != start && intersection->val != destination) {
            string ans1 = "", ans2 = "";
            Coordinates origin;
            origin.x = 0;
            origin.y = 0;
            findPath(intersection, start, destination, "", "", ans1, ans2, origin);
            Point A, B, P;
            A.x = start_point.x;
            A.y = start_point.y;
            B.x = end_point.x;
            B.y = end_point.y;
            P.x = 0;
            P.y = 0;
            int direction = directionOfPoint(A, B, P);
            if (direction == -1) {
                for (auto x : ans1) {
                    res += 'U';
                }
                res += ans2;
            } else {
                for (auto x : ans1) {
                    res += 'U';
                }
                res += ans2;
            }
        } else {
            string ans = "";
            if (intersection->val == start) {
                findDestinationPath(intersection, destination, "", ans);
                res = ans;
            } else {
                findDestinationPath(intersection, start, "", ans);
                for (auto x : ans) {
                    res += 'U';
                }
            }
        }
        return res;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// MLE
