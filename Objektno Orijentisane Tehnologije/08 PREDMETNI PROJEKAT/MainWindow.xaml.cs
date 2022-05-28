using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace OOT_PP_PR83_PR55_2020_BIBLIOTEKA
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private void dodajBibliotekuStrana_Click(object sender, RoutedEventArgs e)
        {
            aktivnost.Source = new Uri("/Biblioteke/DodavanjeBiblioteke.xaml", UriKind.Relative);
        }

        private void pregledSvihBiblioteki_Click(object sender, RoutedEventArgs e)
        {
            aktivnost.Source = new Uri("/Biblioteke/PregledSvihBiblioteka.xaml", UriKind.Relative);
        }

        private void brisanjeBiblioteke_Click(object sender, RoutedEventArgs e)
        {
            aktivnost.Source = new Uri("/Biblioteke/BrisanjeBiblioteke.xaml", UriKind.Relative);
        }
    }
}
