﻿using System;
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

namespace Biblioteka.Biblioteke
{
    public partial class IzmenaBiblioteke : Page
    {
        public IzmenaBiblioteke()
        {
            InitializeComponent();

            #region INICIJALIZACIJA PODATAKA DATACONTEXT I DATAGRID
            DataContext = this;
            dataGridSveBiblioteke.ItemsSource = App.Biblioteke;
            #endregion
        }

        private void dataGridSveBiblioteke_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            var row = ItemsControl.ContainerFromElement((DataGrid)sender, e.OriginalSource as DependencyObject) as DataGridRow;

            if (row == null)
                return;

            if (dataGridSveBiblioteke.SelectedItem == null)
                return;

            App.SelektovanaBiblioteka = dataGridSveBiblioteke.SelectedItem as Biblioteka;

            // Otvaranje prozora za izmenu biblioteke
            BibliotekaInfo bi = new BibliotekaInfo();
            bi.ShowDialog();
            App.SelektovanaBiblioteka = null;
        }

        private void pretraga_TextChanged(object sender, TextChangedEventArgs e)
        {
            List<Biblioteka> pretrazeno = new List<Biblioteka>();
            string unos = (sender as TextBox).Text;

            foreach (Biblioteka k in App.Biblioteke)
            {
                if (k.Naziv.ToLower().Contains(unos.ToLower()))
                {
                    pretrazeno.Add(k);
                }
            }

            dataGridSveBiblioteke.ItemsSource = pretrazeno.ToList();
        }
    }
}
