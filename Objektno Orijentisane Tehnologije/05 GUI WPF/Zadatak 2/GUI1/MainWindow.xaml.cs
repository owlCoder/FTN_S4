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

namespace GUI1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private static int brojac = 0;
        public MainWindow()
        {
            InitializeComponent();
        }
        private void GenerisanjeBtn_Click(object sender, RoutedEventArgs e)
        {
            bool notEmpty = ProveriPoljaForme();

            if (!notEmpty)
            {
                Random rnd = new Random();
                string username = Ime.Text + "_" + Prezime.Text + rnd.Next();
                GenerisanUsername.Text = username;
            }
        }

        private void OcistiPolja_Click(object sender, RoutedEventArgs e)
        {
            Ime.Clear();
            Prezime.Clear();
            GenerisanUsername.Clear();
        }

        private void SacyvajBtn_Click(object sender, RoutedEventArgs e)
        {
            bool notEmpty = ProveriPoljaForme();

            if (!notEmpty && GenerisanUsername.Text != "")
            {
                brojac += 1;
                PoslednjeGenerisano.Text = GenerisanUsername.Text;
                UkupnoGenerisano.Text = brojac.ToString();
            }
            else
            {
                MessageBox.Show("Niste generisali korisnicko ime!", "Greska!", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        private bool ProveriPoljaForme()
        {
            bool notEmpty = false;

            if (Ime.Text == "")
            {
                MessageBox.Show("Niste uneli ime!", "Greska!", MessageBoxButton.OK, MessageBoxImage.Error);
                notEmpty = true;
            }

            if (Prezime.Text == "")
            {
                MessageBox.Show("Niste uneli prezime!", "Greska!", MessageBoxButton.OK, MessageBoxImage.Error);
                notEmpty = true;
            }

            return notEmpty;
        }

    }
}
