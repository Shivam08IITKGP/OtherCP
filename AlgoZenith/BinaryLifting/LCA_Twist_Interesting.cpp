while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1)
        {
            cout << lca(x, y) << endl;
        }
        else
        {
            int lca_xy = lca(x, y);
            int lca_xz = lca(x, z);
            int lca_zy = lca(y, z);
            int test = lca(lca_xz, lca_zy);
            if (lca_xz == lca_zy)
            {
                cout << lca_xy << endl;
            }
            else if (test == lca_xz)
            {
                cout << lca_zy << endl;
            }
            else if (test == lca_zy)
            {
                cout << lca_xz << endl;
            }
            else if (z == lca_xz or z == lca_zy)
            {
                cout << lca_xy << endl;
            }
            else
            {
                cout << z << endl;
            }
        }
    }
