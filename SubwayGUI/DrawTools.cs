using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace SubwayGUI
{
	public class DrawTools
	{
		//画出两点连线，黑色箭头
		public void DrawLine(Graphics g, Point point_start, Point point_end)
		{
			Pen mypen = new Pen(Color.Black,3);
			mypen.EndCap = LineCap.ArrowAnchor;
			g.DrawLine(mypen, point_start, point_end);
		}
		//画蓝色方块，当前站点
		public void DrawBlue(Graphics g, Point p)
	   { 
		SolidBrush brush = new SolidBrush(Color.Blue);
		Size size = new Size(6, 6);
		Rectangle rect = new Rectangle(p, size);
		g.FillEllipse(brush, rect);
        }
	
	   //画红色方块，走过的站点
	    public void DrawRed(Graphics g, Point p)
		{SolidBrush brush = new SolidBrush(Color.Red);
		Size size = new Size(5, 5);
		Rectangle rect = new Rectangle(p, size);
		g.FillEllipse(brush, rect);
		}
}
}
