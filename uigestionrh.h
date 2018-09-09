#ifndef UIGESTIONRH_H
#define UIGESTIONRH_H
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <vector>
#include <QtWebKit/QtWebKit>
#include <QList>
#include <QUrl>
#include "uipassword.h"
#include "promotion.h"
#include "inputcontrol.h"
#include "employee.h"
#include "building.h"
#include "manager.h"
#include <QDesktopServices>
#include "driver.h"
#include "piechartwidget.h"
#include "vacation.h"
#include "mouvement.h"
#include "raises.h"
#include <time.h>
using namespace std;
namespace Ui {
class gestionrh;
}
class gestionrh : public QWidget
{
    Q_OBJECT

public:
    explicit gestionrh(QWidget *parent = 0);
    ~gestionrh();
    void resize_objects();
    void set_session(int,QString);
    void hide_what_needs_to_be_hidden();
    void manage_birthdate();
    void manage_lisence_date();
    bool is_add_data_existant_and_valid();
    bool is_promotion_data_existant_and_valid();
    bool is_mod_data_existant_and_valid();
    void hide_add_alert_labels();
    void hide_mod_alert_labels();
    void insert_employee_data();
    void hide_manager_items();
    void show_manager_items();
    void hide_driver_items();
    void show_driver_items();
    void manage_mod_birthdate();
    void manage_mod_lisence_date();
    void hide_colors();
    void hide_graph_titels();
    void set_graph_header_data(int max);
    void hide_graph_side_bar();
    void insert_employee_combobox_data();
    void hide_vacation_alert_labels();
    void show_me_the_meaning_of_being_lonely();
    void update_table_view();
    void calculate_promotion_salary();
    void hide_promotions_alert_labels();
    void reset_pomotions_labels_and_combos();
    void connect_slots_with_header_signal();
    void manage_vacations_end_dates();
    void manage_mod_vacations_start_dates();
    void manage_mod_vacations_end_dates();
    void manager_vacation_start_dates();
    void insert_raises_combobx_data();
    void load_history_urls();
    bool check_existence(QUrl url);
    void randomise_shifts();
    void manage_schedule(QDate week_start_day ,int day_of_week);





private slots:

    void on_disconnection_clicked();

    void on_pwd_change_clicked();

    void on_post_currentIndexChanged();

    void on_months_b_currentIndexChanged();

    void on_years_b_currentIndexChanged();

    void on_months_led_currentIndexChanged();

    void on_years_led_currentIndexChanged();

    void on_clear_clicked();

    void on_create_employee_clicked();

    void on_interveiwer_search_textEdited();

    void on_interveiwer_search_returnPressed();

    void on_add_cv_clicked();

    void on_add_motivationletter_clicked();

    void on_add_photo_clicked();

    void on_search_employee_textEdited();

    void on_search_employee_returnPressed();

    void on_search_employee_textChanged();

    void on_export_employee_list_clicked();

    void on_mod_id_employee_currentIndexChanged();

    void on_mod_post_currentIndexChanged();

    void on_search_building_textChanged();

    void on_employee_list_doubleClicked(const QModelIndex &index);

    void on_mod_update_employee_clicked();

    void on_mod_clear_clicked();

    void on_delete_employee_clicked();

    void on_vac_id_employee_currentIndexChanged();

    void on_create_vacation_clicked();

    void on_clear_vacation_clicked();

    void on_mod_vac_id_employee_currentIndexChanged();


    void on_statistics_tab_currentChanged();

    void on_statistic_data_currentIndexChanged();

    void on_graph_data_currentIndexChanged();


    void on_Employe_groupe_currentIndexChanged();


    void on_mod_prom_id_employee_currentTextChanged(const QString &arg1);

    void on_mod_prom_Salary_bonus_sp_editingFinished();

    void on_mod_prom_Salary_bonus_sp_valueChanged();

    void on_mod_prom_foreign_post_com_currentTextChanged(const QString &arg1);

    void on_Ch_b_contract_method_stateChanged();

    void on_Ch_b_mod_prom_p_m_stateChanged();

    void on_c_clicked();

    void i_exist(int pos);

    void on_promote_emp_clicked();

    void on_promotion_history_tab_v_doubleClicked(const QModelIndex &index);



    void on_mod_prom_search_name_textChanged(const QString &arg1);

    void on_mod_move_id_employee_currentTextChanged(const QString &arg1);

    void on_mod_move_search_name_textChanged(const QString &arg1);

    void on_mouvement_history_tab_v_doubleClicked(const QModelIndex &index);

    void on_mod_move_search_building_textChanged(const QString &arg1);


    void on_move_building_id_com_currentTextChanged(const QString &arg1);

    void on_move_building_places_left_textChanged(const QString &arg1);

    void on_clear_mouvement_clicked();

    void on_move_employee_clicked();

    void on_mouvement_building_tb_v_doubleClicked(const QModelIndex &index);

    void on_vac_search_name_textChanged(const QString &arg1);

    void on_vacation_employee_list_tv_doubleClicked(const QModelIndex &index);

    void on_number_of_vacation_days_editingFinished();

    void on_late_declared_vacation_clicked();

    void on_number_of_vacation_days_valueChanged(int arg1);

    void on_vac_end_months_currentTextChanged();

    void on_vac_end_years_currentIndexChanged();

    void on_vac_start_years_currentIndexChanged();

    void on_vac_start_months_currentIndexChanged();

    void on_vac_start_days_currentTextChanged();

    void on_enable_or_select_new_raise_clicked();

    void on_clear_raise_clicked();

    void on_add_raise_clicked();

    void on_id_raise_currentTextChanged(const QString &arg1);

    void on_raise_id_employee_currentTextChanged(const QString &arg1);

    void on_raise_search_name_textChanged(const QString &arg1);

    void on_raise_employee_list_tab_v_doubleClicked(const QModelIndex &index);

    void on_take_me_back_to_search_clicked();

    void on_search_raises_textChanged(const QString &arg1);

    void on_go_web_site_clicked();

    void on_reload_url_clicked();

    void on_next_url_clicked();

    void on_last_url_clicked();

    void on_redirect_clicked();

    void on_url_currentTextChanged();

    void on_monday_morning_pb_clicked();

    void on_tuesday_morning_pb_clicked();

    void on_wednsday_morning_pb_clicked();

    void on_thursday_morning_pb_clicked();

    void on_friday_morning_pb_clicked();

    void on_saturday_morning_pb_clicked();

    void on_sunday_morning_pb_clicked();

    void on_sunday_after_noon_pb_clicked();

    void on_saturday_after_noon_pb_clicked();

    void on_friday_after_noon_pb_clicked();

    void on_thursday_after_noon_pb_clicked();

    void on_wednsday_after_noon_pb_clicked();

    void on_tuesday_after_noon_pb_clicked();

    void on_monday_after_noon_pb_clicked();

    void on_shift_go_clicked();

    void on_shift_creating_id_employee_currentTextChanged(const QString &arg1);

    void on_shift_week_currentTextChanged(const QString &arg1);

    void on_shifts_employee_list_doubleClicked(const QModelIndex &index);

    void on_search_employee_2_textChanged(const QString &arg1);

    void on_shift_building_list_doubleClicked(const QModelIndex &index);

    void on_move_shift_building_id_com_currentTextChanged(const QString &arg1);



    void on_assigne_raise_clicked();

    void on_search_raise_update_textChanged(const QString &arg1);

    void on_id_raise_update_currentTextChanged(const QString &arg1);

    void on_raises_table_view_doubleClicked(const QModelIndex &index);

    void on_raises_table_update_view_doubleClicked(const QModelIndex &index);

    void on_submit_update_clicked();

    void on_update_clear_clicked();

    void on_raise_id_employee_reassigne_currentTextChanged(const QString &arg1);

    void on_raise_search_name_reassigne_textChanged(const QString &arg1);

    void on_raises_table_view_reassigne_doubleClicked(const QModelIndex &index);

    void on_add_raise_to_this_employee_clicked();

    void on_search_raise_delete_textChanged(const QString &arg1);

    void on_id_raise_delete_currentTextChanged(const QString &arg1);

    void on_raises_table_view_delete_doubleClicked(const QModelIndex &index);

    void on_delete_search_clear_clicked();

    void on_update_mod_vacation_clicked();

    void on_clear_mod_vacation_clicked();

private:
    Ui::gestionrh *ui;
    password *pwd ;
    QString pass;
    int ide;
    employee *e;
    manager *m;
    driver *d;
    vacation *v;
    promotion *p;
    building *b;
    mouvement *mou;
    raises *r;
    shift ss;
    /*----------------------*/
    QString name;
    QString family_name;
    QDate birthdate;
    QString social_state;
    long int social_sn;
    QString zip_code;
    QString street;
    QString area ;
    QString city;
    int phone_number;
    int Cin ;
    double salary;
    QString post ;
    QString gender ;
    bool activity ;
    QString contract_type ;
    QString paiment_type ;
    int interveiwer ;
    QString c_v ;
    QString m_l;
    QString photo ;
    int workspace ;
/*---------------------*/
    int lisence;
    bool big_trucks;
    bool small_trucks;
    QDate expiration_date;
/*-------------------------*/
    QString pawd;
    QString type;
    QString email;
/*------graphical values------------*/
   int f_height ;
   int f_widht ;
    QString path;
/*---------vacation----------*/
    int vac_holder;
    QString vac_type;
/*---------promotion---------*/
    QString original_p;
    QString foreign_p;
    double bonus_salary;
    int promotion_holder;
/*---------mouvement---------*/
    int original_building;
    int new_building;
    QString description;
    /*--------raises---------*/
    QString title ;
    double amount ;
    /*------web vars-----*/
    vector<QUrl>history;


};
#endif // UIGESTIONRH_H
