#pragma once

#include"cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "map.h"

using namespace ci;

namespace path_finding {

    class PathFindingApp : public ci::app::App {
    public:

        /**
         * creates app
         */
        PathFindingApp();

        /**
         * draws everything on the app
         */
        void draw() override;

        /**
         * called when mouse press id detected
         * @param event information about the press
         */
        void mouseDown(ci::app::MouseEvent event) override;

        /**
         * called when mouse is dragged
         * @param event information about the drag
         */
        void mouseDrag(ci::app::MouseEvent event) override;

    private:
        const size_t kWindowSize = 800;
        const size_t kMargin = 100;
        const vec2 kImageDimension = vec2(20, 30);
        // Whether the start or end point button is selected
        bool is_start_ = true;
        // Whether the show path button is selected
        bool show_path_ = false;
        // The map to draw
        Map map_;

        void drawButtons() const;
    };


}