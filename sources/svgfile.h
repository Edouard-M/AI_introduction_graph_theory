﻿#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED

#include <string>
#include <fstream>
#include <set>

///FIchiers SVG issus des TP précédents

constexpr char defcol[] = "black";

class Svgfile
{
    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour éviter les ouverture multiples
        static std::set<std::string> s_openfiles;

    public:

        Svgfile(std::string _filename = "output.svg", int _width=1000, int _height=800);
        ~Svgfile();

        void addDisk(double x, double y, double r, std::string color=defcol);
        void addCircle(double x, double y, double r, double ep, std::string color=defcol);
        void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
        void addCross(double x, double y, double span, std::string color=defcol);

        void addText(double x, double y, std::string text, std::string color=defcol);
        void addText(double x, double y, double val, std::string color=defcol);

        void addGrid(double span=100.0, bool numbering=true, std::string color="lightgrey");

        void addTriangle(double x1, double y1, double x2, double y2,
                         double x3, double y3, std::string colorFill,
                          double thickness, std::string colorStroke);
        void addTriangle(double x1, double y1, double x2, double y2,
                         double x3, double y3, std::string colorFill=defcol);


        void addQuadri(double x1, double y1, double x2, double y2,
                         double x3, double y3, double x4, double y4, std::string colorFill=defcol);
        void addQuadri(double x1, double y1, double x2, double y2,
                         double x3, double y3, double x4, double y4, std::string colorFill,
                          double thickness, std::string colorStroke);

        void addRectangle(double x1, double y1, double x2, double y2, std::string colorFill);
        void addRectangle(double x1, double y1, double x2, double y2, std::string colorFill,
                          double thickness, std::string colorStroke);
        void addRectangleGrad(double x1, double y1, double x2, double y2, std::string colorFill);

        static std::string makeRGB(int r, int g, int b);

        /// Type non copiable
        Svgfile(const Svgfile&) = delete;
        Svgfile& operator=(const Svgfile&) = delete;
};

std::string makeRGB(int r, int g, int b);

std::string fillBallColor(std::string col);
std::string fillRectColor(std::string col);

#endif // SVGFILE_H_INCLUDED



