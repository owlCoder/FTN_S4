using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Zadatak1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private double total1 = 0;
        private double total2 = 0;

        bool plusButtonClicked = false;
        bool minusButtonClicked = false;
        bool multiplyButtonClicked = false;
        bool divideButtonClicked = false;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnPlus_Click(object sender, RoutedEventArgs e)
        {
            total1 += double.Parse(txtDisplay.Text);
            labelCurrentOperation.Content = txtDisplay.Text + "+";
            txtDisplay.Text = "";

            plusButtonClicked = true;
            minusButtonClicked = false;
            multiplyButtonClicked = false;
            divideButtonClicked = false;
        }
        private void btnMin_Click(object sender, RoutedEventArgs e)
        {
            total1 += double.Parse(txtDisplay.Text);
            labelCurrentOperation.Content = txtDisplay.Text + "-";
            txtDisplay.Text = "";

            plusButtonClicked = false;
            minusButtonClicked = true;
            multiplyButtonClicked = false;
            divideButtonClicked = false;
        }
        private void btnTimes_Click(object sender, RoutedEventArgs e)
        {
            total1 += double.Parse(txtDisplay.Text);
            labelCurrentOperation.Content = txtDisplay.Text + "*";
            txtDisplay.Text = "";

            plusButtonClicked = false;
            minusButtonClicked = false;
            multiplyButtonClicked = true;
            divideButtonClicked = false;
        }
        private void btnDivide_Click(object sender, RoutedEventArgs e)
        {
            total1 += double.Parse(txtDisplay.Text);
            labelCurrentOperation.Content = txtDisplay.Text + "/";
            txtDisplay.Text = "";

            plusButtonClicked = false;
            minusButtonClicked = false;
            multiplyButtonClicked = false;
            divideButtonClicked = true;
        }
        private void btnSqrt_Click(object sender, RoutedEventArgs e)
        {
            labelCurrentOperation.Content += "√" + txtDisplay.Text;

            total1 += Math.Sqrt(double.Parse(txtDisplay.Text));
            txtDisplay.Text = total1.ToString();
        }
        private void btnCE_Click(object sender, RoutedEventArgs e)
        {
            txtDisplay.Text = "0";
            labelCurrentOperation.Content = "";
        }
        private void btnC_Click(object sender, RoutedEventArgs e)
        {
            txtDisplay.Text = "0";
            labelCurrentOperation.Content = "";
        }
        private void btnPlusMin_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text.StartsWith("-"))
            {
                //It's negative now, so strip the `-` sign to make it positive
                txtDisplay.Text = txtDisplay.Text.Substring(1);
            }
            else if (!string.IsNullOrEmpty(txtDisplay.Text) && decimal.Parse(txtDisplay.Text) != 0)
            {
                //It's positive now, so prefix the value with the `-` sign to make it negative
                txtDisplay.Text = "-" + txtDisplay.Text;
            }
        }

        private void btncomma_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text.Contains(","))
            {

            }
            else
            {
                txtDisplay.Text += ",";
            }
        }
        private void btnBack_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "")
            {

            }
            else
            {
                txtDisplay.Text = txtDisplay.Text.Substring(0, txtDisplay.Text.Length - 1);
            }
        }

        private void btnEquals_Click(object sender, RoutedEventArgs e)
        {
            if (plusButtonClicked == true)
            {
                total2 = total1 + double.Parse(txtDisplay.Text);
                labelCurrentOperation.Content = total1 + "+" + double.Parse(txtDisplay.Text);
                txtDisplay.Text = total2.ToString();
                total1 = 0;
            }
            else if (minusButtonClicked == true)
            {
                total2 = total1 - double.Parse(txtDisplay.Text);
                labelCurrentOperation.Content = total1 + "-" + double.Parse(txtDisplay.Text);
                txtDisplay.Text = total2.ToString();
                total1 = 0;
            }
            else if (multiplyButtonClicked == true)
            {
                total2 = total1 * double.Parse(txtDisplay.Text);
                labelCurrentOperation.Content = total1 + "*" + double.Parse(txtDisplay.Text);
                txtDisplay.Text = total2.ToString();
                total1 = 0;
            }
            else if (divideButtonClicked == true)
            {
                total2 = total1 / double.Parse(txtDisplay.Text);
                labelCurrentOperation.Content = total1 + "/" + double.Parse(txtDisplay.Text);
                txtDisplay.Text = total2.ToString();
                total1 = 0;
            }
        }
        private void btn0_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "0";
            }
            else
            {
                txtDisplay.Text += "0";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void btn1_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "1";
            }
            else
            {
                txtDisplay.Text += "1";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void btn2_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "2";
            }
            else
            {
                txtDisplay.Text += "2";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void btn3_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "3";
            }
            else
            {
                txtDisplay.Text += "3";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void btn4_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "4";
            }
            else
            {
                txtDisplay.Text += "4";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void btn5_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "5";
            }
            else
            {
                txtDisplay.Text += "5";
                labelCurrentOperation.Content = txtDisplay.Text;
            }

        }
        private void btn6_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "6";
            }
            else
            {
                txtDisplay.Text += "6";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void btn7_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "7";
            }
            else
            {
                txtDisplay.Text += "7";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void btn8_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "8";
            }
            else
            {
                txtDisplay.Text += "8";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void btn9_Click(object sender, RoutedEventArgs e)
        {
            if (txtDisplay.Text == "0")
            {
                txtDisplay.Text = "9";
            }
            else
            {
                txtDisplay.Text += "9";
                labelCurrentOperation.Content = txtDisplay.Text;
            }
        }
        private void txtDisplay_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
