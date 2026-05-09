class Solution {
private:
    // 工业规范：定义强类型枚举，彻底消灭魔术数字 (0, 1, 2)
    enum class State {
        UNCOVERED,  // 0: 无覆盖
        HAS_CAMERA, // 1: 有摄像头
        COVERED     // 2: 有覆盖
    };

    State traversal(const TreeNode* cur, int& result) { // 加上 const 保护节点不被修改
        // 空节点默认已被覆盖，迫使真实叶子节点变为 UNCOVERED
        if (cur == nullptr) return State::COVERED;

        State left = traversal(cur->left, result);
        State right = traversal(cur->right, result);    

        // 贪心策略 1：只要左右孩子有一个没被覆盖，当前节点必须加摄像头
        if (left == State::UNCOVERED || right == State::UNCOVERED) {
            result++;
            return State::HAS_CAMERA;
        }
        
        // 贪心策略 2：左右孩子至少有一个摄像头，当前节点自然被覆盖
        if (left == State::HAS_CAMERA || right == State::HAS_CAMERA) {
            return State::COVERED;
        }

        // 贪心策略 3：左右孩子都处于 COVERED 状态，当前节点变为无覆盖，交由父节点处理
        return State::UNCOVERED;
    }

public:
    int minCameraCover(TreeNode* root) {
        int result = 0;
        // 根节点特判：如果遍历完根节点依然是 UNCOVERED，只能在根节点硬加一个
        if (traversal(root, result) == State::UNCOVERED) {
            result++;
        }
        return result;
    }
};