//
// Created by Veniamin_Arefev on 29.03.2021.
//
#include <iostream>
#include <map>

enum direction {  // turn left = +1 turn right = -1
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3
};

enum {
    COUNT_OF_DIR = 4,
    SIZE = 9
};

void change_direction(int &cur_dir, int rot_dir) {
    if (rot_dir == LEFT) {
        cur_dir = (cur_dir + COUNT_OF_DIR + 1) % COUNT_OF_DIR;
    } else { // rot_dir == RIGHT
        cur_dir = (cur_dir + COUNT_OF_DIR - 1) % COUNT_OF_DIR;
    }
}

struct Side {
    std::map<std::pair<int, int>, int> &mas;
    std::map<int, Side *> &sides_map;
    char s_char;

    Side(char s) : mas(*new std::map<std::pair<int, int>, int>()),
            sides_map(*new std::map<int, Side *>()), s_char(s) {
    }

    ~Side() {
        delete &mas;
        delete &sides_map;
    }
};

Side *init_sides() {
    Side *forward_side = new Side('F');
    Side *left_side = new Side('L');
    Side *up_side = new Side('U');
    Side *right_side = new Side('R');
    Side *down_side = new Side('D');
    Side *back_side = new Side('B');
    forward_side->sides_map.insert(std::make_pair(UP, up_side));
    forward_side->sides_map.insert(std::make_pair(DOWN, down_side));
    forward_side->sides_map.insert(std::make_pair(LEFT, left_side));
    forward_side->sides_map.insert(std::make_pair(RIGHT, right_side));

    left_side->sides_map.insert(std::make_pair(UP, up_side));
    left_side->sides_map.insert(std::make_pair(DOWN, down_side));
    left_side->sides_map.insert(std::make_pair(LEFT, back_side));
    left_side->sides_map.insert(std::make_pair(RIGHT, forward_side));

    right_side->sides_map.insert(std::make_pair(UP, up_side));
    right_side->sides_map.insert(std::make_pair(DOWN, down_side));
    right_side->sides_map.insert(std::make_pair(LEFT, forward_side));
    right_side->sides_map.insert(std::make_pair(RIGHT, back_side));

    back_side->sides_map.insert(std::make_pair(UP, up_side));
    back_side->sides_map.insert(std::make_pair(DOWN, down_side));
    back_side->sides_map.insert(std::make_pair(LEFT, right_side));
    back_side->sides_map.insert(std::make_pair(RIGHT, left_side));

    up_side->sides_map.insert(std::make_pair(UP, back_side));
    up_side->sides_map.insert(std::make_pair(DOWN, forward_side));
    up_side->sides_map.insert(std::make_pair(LEFT, left_side));
    up_side->sides_map.insert(std::make_pair(RIGHT, right_side));

    down_side->sides_map.insert(std::make_pair(UP, forward_side));
    down_side->sides_map.insert(std::make_pair(DOWN, back_side));
    down_side->sides_map.insert(std::make_pair(LEFT, left_side));
    down_side->sides_map.insert(std::make_pair(RIGHT, right_side));
    return forward_side;
}

void delete_sides(Side *cur_side) {
    delete cur_side->sides_map[RIGHT]->sides_map[RIGHT];
    delete cur_side->sides_map[UP];
    delete cur_side->sides_map[DOWN];
    delete cur_side->sides_map[LEFT];
    delete cur_side->sides_map[RIGHT];
    delete cur_side;
}

int count_sides(Side *cur_side) {
    size_t sides_count = 0;
    // 8 sides with 3 edges, 12 sides with 2 edges and 6 sides with only 1 edge
    auto front_map = cur_side->mas;
    auto up_map = cur_side->sides_map[UP]->mas;
    auto down_map = cur_side->sides_map[DOWN]->mas;
    auto right_map = cur_side->sides_map[RIGHT]->mas;
    auto left_map = cur_side->sides_map[LEFT]->mas;
    auto back_map = cur_side->sides_map[RIGHT]->sides_map[RIGHT]->mas;

    /*
    block sides translation

    (0,0) (0,1) (0,2)
    (1,0) (1,1) (1,2)
    (2,0) (2,1) (2,2)

    */
//sides with 3 edges -- 8 total
    //up blocks
    sides_count += up_map.count(std::make_pair(0, 0)) || left_map.count(std::make_pair(0, 0)) ||
            back_map.count(std::make_pair(0, 2));
    sides_count += up_map.count(std::make_pair(0, 2)) || right_map.count(std::make_pair(0, 2)) ||
            back_map.count(std::make_pair(0, 0));
    sides_count += up_map.count(std::make_pair(2, 0)) || left_map.count(std::make_pair(0, 2)) ||
            front_map.count(std::make_pair(0, 0));
    sides_count += up_map.count(std::make_pair(2, 2)) || right_map.count(std::make_pair(0, 0)) ||
            front_map.count(std::make_pair(0, 2));
    //down blocks
    sides_count += down_map.count(std::make_pair(0, 0)) || left_map.count(std::make_pair(2, 2)) ||
            front_map.count(std::make_pair(2, 0));
    sides_count += down_map.count(std::make_pair(0, 2)) || right_map.count(std::make_pair(2, 0)) ||
            front_map.count(std::make_pair(2, 2));
    sides_count += down_map.count(std::make_pair(2, 0)) || left_map.count(std::make_pair(2, 0)) ||
            back_map.count(std::make_pair(2, 2));
    sides_count += down_map.count(std::make_pair(2, 2)) || right_map.count(std::make_pair(2, 2)) ||
            back_map.count(std::make_pair(2, 0));

//sides with 2 edges -- 12 total
    //up blocks
    sides_count += up_map.count(std::make_pair(0, 1)) || back_map.count(std::make_pair(0, 1));
    sides_count += up_map.count(std::make_pair(1, 0)) || left_map.count(std::make_pair(0, 1));
    sides_count += up_map.count(std::make_pair(1, 2)) || right_map.count(std::make_pair(0, 1));
    sides_count += up_map.count(std::make_pair(2, 1)) || front_map.count(std::make_pair(0, 1));
    //middle blocks
    sides_count += left_map.count(std::make_pair(1, 2)) || front_map.count(std::make_pair(1, 0));
    sides_count += front_map.count(std::make_pair(1, 2)) || right_map.count(std::make_pair(1, 0));
    sides_count += right_map.count(std::make_pair(1, 2)) || back_map.count(std::make_pair(1, 0));
    sides_count += back_map.count(std::make_pair(1, 2)) || left_map.count(std::make_pair(1, 0));
    //down blocks
    sides_count += down_map.count(std::make_pair(0, 1)) || front_map.count(std::make_pair(2, 1));
    sides_count += down_map.count(std::make_pair(1, 0)) || left_map.count(std::make_pair(2, 1));
    sides_count += down_map.count(std::make_pair(1, 2)) || right_map.count(std::make_pair(2, 1));
    sides_count += down_map.count(std::make_pair(2, 1)) || back_map.count(std::make_pair(2, 1));

//sides with 1 edges -- 6 total
    sides_count += front_map.count(std::make_pair(1, 1));
    sides_count += up_map.count(std::make_pair(1, 1));
    sides_count += down_map.count(std::make_pair(1, 1));
    sides_count += right_map.count(std::make_pair(1, 1));
    sides_count += left_map.count(std::make_pair(1, 1));
    sides_count += back_map.count(std::make_pair(1, 1));


//    sides_count += cur_side->sides_map[UP]->mas.size();
//    sides_count += cur_side->sides_map[DOWN]->mas.size();
//    sides_count += cur_side->sides_map[LEFT]->mas.size();
//    sides_count += cur_side->sides_map[RIGHT]->mas.size();
//    sides_count += cur_side->sides_map[RIGHT]->sides_map[RIGHT]->mas.size();
//    sides_count += cur_side->mas.size();
    return (int) sides_count;
}

int main() {
    int cur_x = 1;
    int cur_y = 1;
    int cur_dir = UP;

    Side *cur_side = init_sides();
    Side *forward_side = cur_side;
    cur_side->mas[std::make_pair(cur_x, cur_y)] = 1;

    char input;
    while (std::cin >> input) {
        if (input == 'S') {
            break;
        }
        switch (input) {
            case 'L':
                change_direction(cur_dir, LEFT);
                break;
            case 'R':
                change_direction(cur_dir, RIGHT);
                break;
            case 'F':
                //move forward
                switch (cur_dir) {
                    case UP:
                        if (cur_x != 0) {
                            --cur_x;
                        } else {
                            switch (cur_side->s_char) { //we go from there up
                                case 'F':
                                    cur_x = 2;
                                    break;
                                case 'L':
                                    cur_dir = RIGHT;
                                    cur_x = cur_y;
                                    cur_y = 0;
                                    break;
                                case 'R':
                                    cur_dir = LEFT;
                                    cur_x = 2 - cur_y;
                                    cur_y = 2;
                                    break;
                                case 'U':
                                    cur_dir = DOWN;
                                    cur_y = 2 - cur_y;
                                    break;
                                case 'D':
                                    cur_x = 2;
                                    break;
                                case 'B':
                                    cur_dir = DOWN;
                                    cur_y = 2 - cur_y;
                                    break;
                            }
                            cur_side = cur_side->sides_map[UP];
                        }
                        break;
                    case DOWN:
                        if (cur_x != 2) {
                            ++cur_x;
                        } else {
                            switch (cur_side->s_char) { //we go from there up
                                case 'F':
                                    cur_x = 0;
                                    break;
                                case 'L':
                                    cur_dir = RIGHT;
                                    cur_x = 2 - cur_y;
                                    cur_y = 0;
                                    break;
                                case 'R':
                                    cur_dir = LEFT;
                                    cur_x = cur_y;
                                    cur_y = 2;
                                    break;
                                case 'U':
                                    cur_x = 0;
                                    break;
                                case 'D':
                                    cur_dir = UP;
                                    cur_y = 2 - cur_y;
                                    break;
                                case 'B':
                                    cur_dir = UP;
                                    cur_y = 2 - cur_y;
                                    break;
                            }
                            cur_side = cur_side->sides_map[DOWN];
                        }
                        break;
                    case LEFT:
                        if (cur_y != 0) {
                            --cur_y;
                        } else {
                            switch (cur_side->s_char) { //we go from there up
                                case 'F':
                                    cur_y = 2;
                                    break;
                                case 'L':
                                    cur_y = 2;
                                    break;
                                case 'R':
                                    cur_y = 2;
                                    break;
                                case 'U':
                                    cur_dir = DOWN;
                                    cur_y = cur_x;
                                    cur_x = 0;
                                    break;
                                case 'D':
                                    cur_dir = UP;
                                    cur_y = 2 - cur_x;
                                    cur_x = 2;
                                    break;
                                case 'B':
                                    cur_y = 2;
                                    break;
                            }
                            cur_side = cur_side->sides_map[LEFT];
                        }
                        break;
                    case RIGHT:
                        if (cur_y != 2) {
                            ++cur_y;
                        } else {
                            switch (cur_side->s_char) { //we go from there up
                                case 'F':
                                    cur_y = 0;
                                    break;
                                case 'L':
                                    cur_y = 0;
                                    break;
                                case 'R':
                                    cur_y = 0;
                                    break;
                                case 'U':
                                    cur_dir = DOWN;
                                    cur_y = 2 - cur_x;
                                    cur_x = 0;
                                    break;
                                case 'D':
                                    cur_dir = UP;
                                    cur_y = cur_x;
                                    cur_x = 2;
                                    break;
                                case 'B':
                                    cur_y = 0;
                                    break;
                            }
                            cur_side = cur_side->sides_map[RIGHT];
                        }
                        break;
                }
                cur_side->mas[std::make_pair(cur_x, cur_y)] = 1;
                break;
        }
//        std::cout << cur_dir << std::endl;
    }

    std::cout << count_sides(forward_side) << std::endl;

    delete_sides(forward_side);
}
