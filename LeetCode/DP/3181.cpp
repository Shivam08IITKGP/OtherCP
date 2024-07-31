class Solution
{
public:
    int maxTotalReward(vector<int> &r)
    {
        int n = r.size(), j = 0;
        sort(r.begin(), r.end());
        bitset<100000> bs(1), mask;

        for (auto ele : r)
        {
            for (; j < ele; j++)
                mask.set(j); // mask[j] = 1

            // Debug print: Last 10 bits of bs and mask before the operation
            printLast10Bits(bs, "bs before operation");
            printLast10Bits(mask, "mask before operation");

            bs |= (bs & mask) << ele;

            // Debug print: Last 10 bits of bs and mask after the operation
            printLast10Bits(bs, "bs after operation");
            printLast10Bits(mask, "mask after operation");
        }

        for (int i = 99999; i >= 0; i--)
        {
            if (bs.test(i)) // checks whether the given index is set or not
                return i;
        }
        return 0;
    }

private:
    void printLast10Bits(const bitset<100000> &bs, const string &label)
    {
        cout << label << ": ";
        for (int i = 20; i >= 0; --i)
        {
            cout << bs[i];
        }
        cout << endl;
    }
};
