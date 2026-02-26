import numpy as np
import matplotlib.pyplot as plt

days_full = np.array([0, 0.25, 0.5, 1, 2, 3, 4, 5, 6, 8, 10, 12, 16, 21])
micrograms_full = np.array([2.5, 3.6, 5.3, 9.5, 14.0, 16.5, 18.8, 21.5, 23.2, 26.8, 28.4, 28.4, 28.5, 29.5])

p_deg1 = [2.61051515, 4.1420202]
p_deg2 = [-0.17323616, 4.34287677, 2.83030303]
p_deg3 = [0.03554161, -0.70776717, 6.16238618, 2.2458042]
p_exp = [30.0152, 0.2031] 

def exponential_model(params, t):
    C, a = params
    return C * (1 - np.exp(-a * t))

days_smooth = np.linspace(0, 21, 200)

y_pred_poly1 = np.polyval(p_deg1, days_smooth)
y_pred_poly2 = np.polyval(p_deg2, days_smooth)
y_pred_poly3 = np.polyval(p_deg3, days_smooth)
y_pred_exp = exponential_model(p_exp, days_smooth)

plt.figure(figsize=(12, 8))

plt.plot(days_full, micrograms_full, 'ko', markersize=8, 
         markerfacecolor='k', label='Dữ liệu thực tế (Đầy đủ 21 ngày)')

plt.plot(days_smooth, y_pred_poly1, 'b--', 
         label=f'Bậc 1 (SSR 0-10 ngày ≈ 188.9)')
         
plt.plot(days_smooth, y_pred_poly2, 'g:', linewidth=2, 
         label=f'Bậc 2 (SSR 0-10 ngày ≈ 11.2)')
         
plt.plot(days_smooth, y_pred_poly3, 'm-.', linewidth=2, 
         label=f'Bậc 3 (SSR 0-10 ngày ≈ 1.2)')
         
plt.plot(days_smooth, y_pred_exp, 'r-', linewidth=2.5, 
         label=f'Hàm mũ (SSR 0-10 ngày ≈ 4.6)')

plt.axvline(10, color='gray', linestyle='--', label='Kết thúc dữ liệu training')

plt.title('Nhiệm vụ 8: Khả năng Dự đoán (Extrapolation) của 4 Mô hình')
plt.xlabel('Ngày (Day)')
plt.ylabel('Microgram thuốc được giải phóng (Micrograms)')
plt.legend(loc='upper left') 
plt.grid(True)
plt.ylim(0, 50) 
plt.xlim(0, 21)

plt.show()