#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// โครงสร้างข้อมูลสำหรับเก็บข้อมูลบ้าน
struct House {
    int l, r; // ช่วงเวลา
};

// ฟังก์ชันหลัก
int main() {
    int n;
    cin >> n;

    vector<House> houses(n);

    // รับข้อมูลช่วงเวลา l_i และ r_i
    for (int i = 0; i < n; ++i) {
        cin >> houses[i].l >> houses[i].r;
    }

    // เรียงบ้านตาม r_i จากน้อยไปมาก (หาก r_i เท่ากัน ให้เรียงตาม l_i)
    sort(houses.begin(), houses.end(), [](const House &a, const House &b) {
        return a.r < b.r; // เรียงตาม r อย่างเดียว (ไม่ต้องสนใจ l)
    });

    // Set สำหรับเก็บวันที่ที่ยังไม่ได้ใช้
    set<int> available_days;

    // เพิ่มวันที่ทั้งหมดที่เป็นไปได้ใน Set (1 ถึง 10^9)
    for (int i = 1; i <= n; ++i) {
        available_days.insert(i);
    }

    int max_reviews = 0;

    // ลองจัดบ้านทีละหลัง
    for (const auto &house : houses) {
        // หาวันที่เร็วที่สุดที่อยู่ในช่วง [l, r]
        auto it = available_days.lower_bound(house.l);
        if (it != available_days.end() && *it <= house.r) {
            // หากเจอวันที่สามารถใช้ได้
            available_days.erase(it); // ใช้วันนั้นแล้วลบออก
            max_reviews++;           // นับบ้านที่ได้คะแนน 5 ดาวเพิ่ม
        }
    }

    // แสดงผลลัพธ์
    cout << max_reviews << endl;
    return 0;
}
