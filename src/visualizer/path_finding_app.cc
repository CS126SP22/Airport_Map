#include <visualizer/path_finding_app.h>

namespace path_finding {


    PathFindingApp::PathFindingApp()
            : map_(glm::vec2(kMargin, kMargin), kImageDimension,
                     vec2(kWindowSize - kMargin, kWindowSize - 2 * kMargin)) {
        app::setWindowSize(kWindowSize + 6 * kMargin, (int) kWindowSize);
    }

    void PathFindingApp::draw() {
        Color8u background_color(0, 0, 0);
        gl::clear(background_color);

        map_.DrawHelper();

        //draws text on screen
        gl::drawStringCentered(
                "Path Finding App",
                glm::vec2((kWindowSize + 6 * kMargin) / 2, kMargin / 2), Color("white"));

        gl::drawStringCentered(
                "Buttons",
                glm::vec2(kWindowSize + 4 * kMargin, kMargin), Color("white"));

        drawButtons();

    }

    void PathFindingApp::mouseDown(app::MouseEvent event) {
        if (event.isLeftDown())
            map_.Brush(event.getPos(), false, false);
        else
            map_.Brush(event.getPos(), true, is_start_);

        vec2 pos = event.getPos();
        // switches is_start if mouse click is in the right place
        if (pos.x >= kWindowSize + 7.0f * kMargin / 2 &&
            pos.x <= kWindowSize + 9.0f * kMargin / 2 && pos.y >= kMargin + 30.0f &&
            pos.y <= 3.0f * kMargin / 2 + 30) {
            is_start_ = true;
        } else if (pos.x >= kWindowSize + 7.0f * kMargin / 2 &&
                   pos.x <= kWindowSize + 9.0f * kMargin / 2 &&
                   pos.y >= 3.0f * kMargin / 2 + 60 && pos.y <= 2.0f * kMargin + 60) {
            is_start_ = false;
        } else if (pos.x >= kWindowSize + 7.0f * kMargin / 2 &&
                   pos.x <= kWindowSize + 9.0f * kMargin / 2 &&
                   pos.y >= 2.0f * kMargin + 90 && pos.y <= 5.0f * kMargin / 2 + 90) {
            map_.Clear();
        } else if (pos.x >= kWindowSize + 7.0f * kMargin / 2 &&
                   pos.x <= kWindowSize + 9.0f * kMargin / 2 &&
                   pos.y >= 5.0f * kMargin / 2 + 120 &&
                   pos.y <= 3.0f * kMargin + 120) {
            map_.ShowPath();
            show_path_ = !show_path_;
        } else if (pos.x >= kWindowSize + 7.0f * kMargin / 2 &&
                   pos.x <= kWindowSize + 9.0f * kMargin / 2 &&
                   pos.y >= 3.0f * kMargin + 150 &&
                   pos.y <= 7.0f * kMargin / 2 + 150) {
            // loads a graph from a file
            std::ifstream is =
                    std::ifstream(
                            "/Users/wangshuo/Cinder/my-projects/final-project-ws9922/data/map.txt");
            if (!is.eof()) {
                is >> map_;
            }
        } else if (pos.x >= kWindowSize + 7.0f * kMargin / 2 &&
                   pos.x <= kWindowSize + 9.0f * kMargin / 2 &&
                   pos.y >= 7.0f * kMargin / 2 + 180 &&
                   pos.y <= 4.0f * kMargin + 180) {
            // loads a graph from a file
            std::ofstream os =
                    std::ofstream(
                            "/Users/wangshuo/Cinder/my-projects/final-project-ws9922/data/map.txt");
            os << map_;
        }
    }

    void PathFindingApp::mouseDrag(app::MouseEvent event) {
        if (event.isLeftDown())
            map_.Brush(event.getPos(), false, false);
        else
            map_.Brush(event.getPos(), true, is_start_);
    }

    void PathFindingApp::drawButtons() const {

        gl::drawStringCentered(
                "Choose Starting Point",
                glm::vec2(kWindowSize + 4 * kMargin, kMargin + 20), Color("white"));

        gl::drawStringCentered(
                "Choose Ending Point",
                glm::vec2(kWindowSize + 4 * kMargin, 3 * kMargin / 2 + 50), Color("white"));

        gl::drawStringCentered(
                "Clear Graph",
                glm::vec2(kWindowSize + 4 * kMargin, 9 * kMargin / 4 + 90), Color("white"));

        gl::drawStringCentered(
                "Show Path",
                glm::vec2(kWindowSize + 4 * kMargin, 11 * kMargin / 4 + 120), Color("white"));

        gl::drawStringCentered(
                "Load Graph",
                glm::vec2(kWindowSize + 4 * kMargin, 13 * kMargin / 4 + 150), Color("white"));

        gl::drawStringCentered(
                "Save Graph",
                glm::vec2(kWindowSize + 4 * kMargin, 15 * kMargin / 4 + 180), Color("white"));

        Color start_color = is_start_ ? "yellow" : "white";
        Color end_color = is_start_ ? "white" : "yellow";
        Color show_path_color = show_path_ ? "yellow" : "white";


        gl::color(start_color);
        vec2 top_left_start_outline(kWindowSize + 7 * kMargin / 2, kMargin + 30);
        vec2 bottom_right_start_outline = top_left_start_outline + vec2(kMargin, kMargin / 2);
        Rectf start_point_outline(top_left_start_outline, bottom_right_start_outline);
        gl::drawStrokedRect(start_point_outline);

        gl::color(Color("lime"));
        vec2 top_left_start =
                (top_left_start_outline + bottom_right_start_outline) / vec2(2, 2) - vec2(kMargin / 7, kMargin / 7);
        vec2 bottom_right_start = top_left_start + vec2(2 * kMargin / 7, 2 * kMargin / 7);
        Rectf start_point_pic(top_left_start, bottom_right_start);
        gl::drawSolidRect(start_point_pic);

        gl::color(end_color);
        vec2 top_left_end_outline(kWindowSize + 7 * kMargin / 2, 3 * kMargin / 2 + 60);
        vec2 bottom_right_end_outline = top_left_end_outline + vec2(kMargin, kMargin / 2);
        Rectf end_point_outline(top_left_end_outline, bottom_right_end_outline);
        gl::drawStrokedRect(end_point_outline);

        gl::color(Color("red"));
        vec2 top_left_end =
                (top_left_end_outline + bottom_right_end_outline) / vec2(2, 2) - vec2(kMargin / 7, kMargin / 7);
        vec2 bottom_right_end = top_left_end + vec2(2 * kMargin / 7, 2 * kMargin / 7);
        Rectf end_point_pic(top_left_end, bottom_right_end);
        gl::drawSolidRect(end_point_pic);

        gl::color(Color("white"));
        vec2 top_left_clear(kWindowSize + 7 * kMargin / 2, 2 * kMargin + 90);
        vec2 bottom_right_clear = top_left_clear + vec2(kMargin, kMargin / 2);
        Rectf clear_outline(top_left_clear, bottom_right_clear);
        gl::drawStrokedRect(clear_outline);

        gl::color(show_path_color);
        vec2 top_left_toggle(kWindowSize + 7 * kMargin / 2, 5 * kMargin / 2 + 120);
        vec2 bottom_right_toggle = top_left_toggle + vec2(kMargin, kMargin / 2);
        Rectf toggle_outline(top_left_toggle, bottom_right_toggle);
        gl::drawStrokedRect(toggle_outline);

        gl::color(Color("white"));
        vec2 top_left_load(kWindowSize + 7 * kMargin / 2, 3 * kMargin + 150);
        vec2 bottom_right_load = top_left_load + vec2(kMargin, kMargin / 2);
        Rectf load_outline(top_left_load, bottom_right_load);
        gl::drawStrokedRect(load_outline);

        gl::color(Color("white"));
        vec2 top_left_save(kWindowSize + 7 * kMargin / 2, 7 * kMargin / 2 + 180);
        vec2 bottom_right_save = top_left_save + vec2(kMargin, kMargin / 2);
        Rectf save_outline(top_left_save, bottom_right_save);
        gl::drawStrokedRect(save_outline);

    }


}