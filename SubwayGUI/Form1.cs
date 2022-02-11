using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;
using System.Threading;

namespace SubwayGUI
{
    public partial class Form1 : Form
    {

        [DllImport("subway_dll.dll", EntryPoint = "ConsoleInterface", CallingConvention = CallingConvention.Cdecl)]
        public static extern void ConsoleInterface(int type, ref byte input, ref byte output);

        //存储所有站点位置
        public Dictionary<string, Point> Map = new Dictionary<string, Point>();
        public static Graphics graphics = null;
        string p1 = null;
        string p2 = null;
        int count = 0;
        string[] sArray;
        int flag = 0;//用来区别三种查询

        public Form1()
        {
            InitializeComponent();
            Form1.graphics = pictureBox_map.CreateGraphics();
            //读取文本文件
            this.ReadFile();
        }
        public void ReadFile()
        {
            FileStream file = new FileStream("Map.txt", FileMode.Open, FileAccess.Read);
            StreamReader streamReader = new StreamReader(file, System.Text.Encoding.Default);
            streamReader.BaseStream.Seek(0, SeekOrigin.Begin);
            Point point = new Point();
            //以每一行为单位node
            string ans_line = streamReader.ReadLine();
            while (ans_line != null)
            {   //将每一行分割 # 1 苹果园 176 360
                string[] sArray = ans_line.Split(' ');
                //读完了所有站点
                if (sArray[0] != "#") break;
                point.X = int.Parse(sArray[3]);
                point.Y = int.Parse(sArray[4]);
                Map.Add(sArray[2], point);

                ans_line = streamReader.ReadLine();
            }
            streamReader.Close();
        }


        public Point Position(Point point)
        {
            point.X = (int)(point.X * pictureBox_map.Width / 1040.0);
            point.Y = (int)(point.Y * pictureBox_map.Height / 710.0);
            return point;
        }

        public void Draw(Object obj)
        {
            string ans = obj.ToString();
            //去除首尾的\0字符
            ans = ans.Trim('\0');
            sArray = ans.Split(' ');
            int len = 0;
            //站点数
            DrawTools draw = new DrawTools();
            count = 0;
            //第一个站点
            int indexfirst = 0;//第一个站点位置
            int indexfront = 0;
            int indexnext = 0;
            if (flag == 3)
            {
                indexfirst = 1; len = sArray.Length;
            }
            if (flag == 3 || flag == 4)
            {
                indexfirst = 1; len = sArray.Length;
            }//查询遍历
            if (flag == 5)
            {
                indexfirst = 0; len = sArray.Length - 1;
            }//查询线路
            draw.DrawBlue(graphics, Position(Map[sArray[indexfirst]]));
            count++;
            Thread.Sleep(30);

            for (int i = indexfirst + 1; i < len; i++)
            {
                indexfront = i - 1;
                indexnext = i + 1;
                //站点信息
                if (Map.ContainsKey(sArray[i]))
                {
                    p1 = sArray[indexfront];
                    p2 = sArray[i];
                    //前一个点是站点，变红
                    if (Map.ContainsKey(p1))
                        draw.DrawRed(graphics, Position(Map[p1]));
                    //当前点，变蓝
                    draw.DrawBlue(graphics, Position(Map[p2]));
                    count++;
                    Thread.Sleep(30);
                    //两点画线
                    draw.DrawLine(graphics, Position(Map[p1]), Position(Map[p2]));
                }

                //换乘信息
                if (!Map.ContainsKey(sArray[i]))//跨过当前点,表示换乘信息
                {
                    p1 = sArray[indexfront];
                    p2 = sArray[indexnext];
                    //前一个点是站点，变红
                    if (Map.ContainsKey(p1))
                        draw.DrawRed(graphics, Position(Map[p1]));
                    //直接跳到下一个站点，变蓝
                    string testttt = p2;
                    draw.DrawBlue(graphics, Position(Map[p2]));
                    count += 3;
                    //换乘连接的两点画线
                    draw.DrawLine(graphics, Position(Map[p1]), Position(Map[p2]));
                    i++;//直接跳到next的next
                }

            }

            //最后一个点变红
            draw.DrawRed(graphics, Position(Map[sArray[len - 1]]));

        }

        //遍历查询按钮 4
        private void button_traverse_Click(object sender, EventArgs e)
        {
            flag = 4;
            Bitmap bitmap = new Bitmap(@"subway_map.jpg");
            Rectangle r = new Rectangle(0, 0, this.pictureBox_map.Size.Width, this.pictureBox_map.Size.Height);
            Form1.graphics.DrawImage(bitmap, r);  // 刷新地图
            count = 0;
            //读取遍历起点站
            string str = textBox_traverse.Text;
            //判断输入起点站是否正确
            if (str != null)
            {
                if (Map.ContainsKey(str.ToString()))
                {
                    string argv = str.ToString();
                    byte[] byteInput = Encoding.Default.GetBytes(argv);
                    byte[] byteOutput = new byte[10240];
                    ConsoleInterface(4, ref byteInput[0], ref byteOutput[0]);
                    string ans = System.Text.Encoding.Default.GetString(byteOutput, 0, byteOutput.Length);
                    Draw(ans);
                    label_station.Text = count.ToString();
                }
                else
                { MessageBox.Show("站点不存在!"); }
            }
            else { MessageBox.Show("请输入站点名！"); }
        }

        //线路查询按钮 5
        private void button_line_Click(object sender, EventArgs e)
        {
            flag = 5;
            // 刷新地图
            Bitmap bitmap = new Bitmap(@"subway_map.jpg");
            Rectangle r = new Rectangle(0, 0, this.pictureBox_map.Size.Width, this.pictureBox_map.Size.Height);
            Form1.graphics.DrawImage(bitmap, r);
            count = 0;
            //读取线路名
            string str = textBox_line.Text;
            //判断是否输入线路名
            if (str != null)
            {
                string argv = str.ToString();
                byte[] byteInput = Encoding.Default.GetBytes(argv);
                byte[] byteOutput = new byte[10240];
                ConsoleInterface(1, ref byteInput[0], ref byteOutput[0]);
                string ans = System.Text.Encoding.Default.GetString(byteOutput, 0, byteOutput.Length);
                Draw(ans);
                label_station.Text = count.ToString();
            }
            else { MessageBox.Show("请输入线路名！"); }

        }

        private void button_shortest_Click(object sender, EventArgs e)
        {
            flag = 3;
            // 刷新地图
            Bitmap bitmap = new Bitmap(@"subway_map.jpg");
            Rectangle r = new Rectangle(0, 0, this.pictureBox_map.Size.Width, this.pictureBox_map.Size.Height);
            Form1.graphics.DrawImage(bitmap, r);
            count = 0;
            //读取线路名
            string str_start = textBox_start.Text;
            string str_end = textBox_end.Text;
            //判断是否输入线路名
            if (str_start != null && str_end != null)
            {
                if (Map.ContainsKey(str_start.ToString()) && Map.ContainsKey(str_end.ToString()))
                {
                    string argv = str_start.ToString() + " " + str_end.ToString();
                    byte[] byteInput = Encoding.Default.GetBytes(argv);
                    byte[] byteOutput = new byte[10240];
                    ConsoleInterface(2, ref byteInput[0], ref byteOutput[0]);
                    string ans = System.Text.Encoding.Default.GetString(byteOutput, 0, byteOutput.Length);
                    Draw(ans);
                    label_station.Text = count.ToString();
                }
                else { MessageBox.Show("请输入正确的站点名！"); }
            }
            else { MessageBox.Show("请输入完整的站点名！"); }
        }
    }
}
