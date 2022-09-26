//
//  LoginViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 23/09/22.
//

import UIKit

class LoginViewController: UIViewController {

    @IBOutlet weak var loginButtonEddit: UIButton!
    
    @IBOutlet weak var emailTF: UITextField!
    @IBOutlet weak var pwTF: UITextField!
    
    var viewModel: LoginViewModel!
        
    override func viewDidLoad() {
        super.viewDidLoad()
        viewModel = LoginViewModel(delegate: self)
        setupButton()
        pwField()
    }
    @IBAction func registerButton(_ sender: Any) {
        let myViewController = Register2ViewController()
        myViewController.modalPresentationStyle = .fullScreen
        self.present(myViewController, animated: false, completion: nil)
    }
    
    private func pwField() {
        pwTF.isSecureTextEntry = true
    }
    

    private func setupButton() {
        loginButtonEddit.layer.cornerRadius = 20
        loginButtonEddit.layer.shadowColor = UIColor.black.cgColor
        loginButtonEddit.layer.shadowOffset = CGSize(width: 0.0, height: 4.0)
        loginButtonEddit.layer.shadowRadius = 4.0
        loginButtonEddit.layer.shadowOpacity = 0.5
        loginButtonEddit.layer.masksToBounds = false
    }

    @IBAction func loginButton(_ sender: Any) {
        viewModel.postLogUser(email: emailTF.text ?? "", password: pwTF.text ?? "")
    }
}

extension LoginViewController: ServiceDelegate {
    func dataSucess() {
        let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
            self.dismiss(animated: false)
        }))
        self.present(alert, animated: true)
        UserDefaults.standard.set(true, forKey: "logado")
        UserDefaults.standard.set(emailTF.text, forKey: "email")
    }
        
    func dataFail(error: Error) {
        let alert = UIAlertController(title: "Erro", message: error.localizedDescription, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .destructive, handler: nil))
        self.present(alert, animated: true)
    }
        
    func showLoad() {
        showSpinner(onView: view)
    }
        
    func removeLoad() {
        removeSpinner()
    }
}
